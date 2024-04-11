#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=300005;

struct State
{
	int len,par,to[26],sz,ls;
};
State T[maxn];

int p,q,last,st;

int bh[maxn],bto[maxn],bnx[maxn],bt;

void belrel(int u,int b)
{
	bt++;
	bto[bt]=b;
	bnx[bt]=bh[u];
	bh[u]=bt;
}

void mark(int p,int cur)
{
	for (int i=p;i;i=T[i].par)
		if (T[i].ls!=cur)
		{
			T[i].ls=cur;
			T[i].sz++;
		}
		else
			return;
}

void extend(char c,int cur)
{
	if (T[last].to[c-'a'])
	{
		q=T[last].to[c-'a'];
		if (T[q].len==T[last].len+1)
		{
			last=q;
			mark(last,cur);
			belrel(last,cur);
			return;
		}
		else
		{
			T[++st].len=T[last].len+1;
			memcpy(T[st].to,T[q].to,sizeof(T[q].to));
			T[st].sz=T[q].sz;
			T[st].ls=T[q].ls;
			T[st].par=T[q].par;
			T[q].par=st;
			p=last;
			while (p&&T[p].to[c-'a']==q)
			{
				T[p].to[c-'a']=st;
				p=T[p].par;
			}
			last=st;
			mark(last,cur);
			belrel(last,cur);
			return;
		}
	}
	T[++st].len=T[last].len+1;
	p=last;
	while (p&&!T[p].to[c-'a'])
	{
		T[p].to[c-'a']=st;
		p=T[p].par;
	}
	q=T[p].to[c-'a'];
	if (p==0||T[q].len==T[p].len+1)
	{
		T[st].par=p==0?1:q;
		last=st;
		mark(last,cur);
		belrel(last,cur);
		return;
	}
	T[++st].len=T[p].len+1;
	memcpy(T[st].to,T[q].to,sizeof(T[q].to));
	T[st].sz=T[q].sz;
	T[st].ls=T[q].ls;
	T[st].par=T[q].par;
	T[q].par=st;
	T[st-1].par=st;
	while (p&&T[p].to[c-'a']==q)
	{
		T[p].to[c-'a']=st;
		p=T[p].par;
	}
	last=st-1;
	mark(last,cur);
	belrel(last,cur);
}

char s[maxn];

int n,k,i,j;

int h[maxn],to[maxn],nx[maxn],et;

void addedge(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}

long long key[maxn],ans[maxn];

void dfs(int u,int f)
{
	if (T[u].sz>=k)
		key[u]=T[u].len-T[f].len;
	if (u==1)
		key[u]=0;
	key[u]+=key[f];
	for (int i=h[u];i;i=nx[i])
		dfs(to[i],u);
}

int main()
{
	last=++st;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (j=1;s[j];j++)
			extend(s[j],i);
		last=1;
	}
	for (i=2;i<=st;i++)
		addedge(T[i].par,i);
	dfs(1,0);
	for (i=1;i<=st;i++)
		for (j=bh[i];j;j=bnx[j])
			ans[bto[j]]+=key[i];
	for (i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
	return 0;
}