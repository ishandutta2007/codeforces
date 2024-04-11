#include <cstdio>
#include <algorithm>
using namespace std;
const int N=600005;
int n,q,lim;
struct node
{
	int f,ch[2];
	bool rev;
	bool cov,cs,add,xs,xv,lg,hlg;
};
node t[N];
int st[N],cnt;
int u,v,x;
bool isroot(int p)
{
	return t[t[p].f].ch[0]!=p&&t[t[p].f].ch[1]!=p;
}
bool getlr(int p)
{
	return t[t[p].f].ch[1]==p;
}
void pushdown(int p)
{
	if (t[p].add)
	{
		if (t[p].ch[0])
		{
			if (t[p].ch[0]>lim)
				t[t[p].ch[0]].cov=1;
			t[t[p].ch[0]].add=1;
			if (t[t[p].ch[0]].hlg)
				t[t[p].ch[0]].cs=1;
		}
		if (t[p].ch[1])
		{
			if (t[p].ch[1]>lim)
				t[t[p].ch[1]].cov=1;
			t[t[p].ch[1]].add=1;
			if (t[t[p].ch[1]].hlg)
				t[t[p].ch[1]].cs=1;
		}
		t[p].add=0;
	}
	if (t[p].rev)
	{
		t[p].rev^=1;
		swap(t[p].ch[0],t[p].ch[1]);
		t[t[p].ch[0]].rev^=1;
		t[t[p].ch[1]].rev^=1;
	}
}
void update(int p)
{
	t[p].xs=t[p].xv^t[t[p].ch[0]].xs^t[t[p].ch[1]].xs;
	t[p].cs=t[p].cov|t[t[p].ch[0]].cs|t[t[p].ch[1]].cs;
	t[p].hlg=t[p].lg|t[t[p].ch[0]].hlg|t[t[p].ch[1]].hlg;
}
void rotate(int p)
{
	int y=t[p].f,z=t[y].f;
	bool q=getlr(p);
	if (!isroot(y))
		t[z].ch[getlr(y)]=p;
	t[t[p].ch[!q]].f=y;
	t[y].f=p;
	t[p].f=z;
	t[y].ch[q]=t[p].ch[!q];
	t[p].ch[!q]=y;
	update(y);
	update(p);
}
void splay(int p)
{
	if (!p)
		return;
	int q,c=0;
	st[++c]=p;
	for (q=p;!isroot(q);q=t[q].f)
		st[++c]=t[q].f;
	while (c)
		pushdown(st[c--]);
	while (!isroot(p))
	{
		q=t[p].f;
		if (!isroot(q))
			rotate(getlr(p)^getlr(q)?p:q);
		rotate(p);
	}
	update(p);
}
void access(int p)
{
	int c=0,q=p;
	while (p)
	{
		splay(p);
		t[p].ch[1]=c;
		c=p;
		p=t[p].f;
	}
	splay(q);
}
void chgroot(int p)
{
	access(p);
	t[p].rev^=1;
}
void link(int x,int y)
{
	chgroot(x);
	t[x].f=y;
	splay(x);
}
void cut(int x,int y)
{
	chgroot(x);
	access(y);
	t[y].ch[0]=t[x].f=0;
}
void cover(int x,int y)
{
	chgroot(x);
	access(y);
	t[y].add|=1;
	if (y>lim)
		t[y].cov|=1;
	if (t[y].hlg)
		t[y].cs|=1;
}
int main()
{
	scanf("%d%d",&n,&q);
	lim=n;
	while (q--)
	{
		scanf("%d%d%d",&u,&v,&x);
		chgroot(u);
		access(v);
		if (isroot(u))
		{
			n++;
			t[n].xv=x;
			t[n].xs=x;
			t[n].lg=t[n].hlg=1;
			link(u,n);
			link(n,v);
			printf("YES\n");
			continue;
		}
		if (t[v].cs||(t[v].xs^x)!=1)
			printf("NO\n");
		else
		{
			cover(u,v);
			printf("YES\n");
		}
	}
	return 0;
}