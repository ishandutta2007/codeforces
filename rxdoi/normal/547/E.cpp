#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=4e5+19,Nq=5e5+19;
typedef long long LL;
struct node
{
	node *Par,*go[26];
	int val;
} Nd[N],*cur=Nd,*Last,*rt;

struct Edge {int y,nxt;} E[N];
struct Qry
{
	int x,k,f,ID;
	bool operator < (const Qry& B) const {return x<B.x;}
} Q[Nq*2];
int El[N],In[N],Out[N],Ed[N];
int n,m,Ql,Qr,k,cnt,tot,Qc,Len,c=1;
char s[N];
string S[N];

//SAM
node *New(int v) {return cur->val=v,cur++;}
void Extend(int x)
{
	node *p=Last,*np=p->go[x];
	if (np&&np->val==p->val+1)
	{
		Last=np;return;
	} else np=New(p->val+1);
	for (;p&&!p->go[x];p=p->Par) p->go[x]=np;
	if (!p) np->Par=rt;else
	{
		node *t=p->go[x];
		if (t->val==p->val+1) np->Par=t;else
		{
			node *nt=New(p->val+1);
			nt->Par=t->Par,t->Par=np->Par=nt;
			memcpy(nt->go,t->go,sizeof(t->go));
			for (;p&&p->go[x]==t;p=p->Par) p->go[x]=nt;
		}
	}
	Last=np;
}

LL C[N],Ans[Nq];
void Add(int x) {for (;x<=tot;x+=x&-x) C[x]++;}
LL Query(int x) {LL Ans=0;for (;x;x-=x&-x) Ans+=C[x];return Ans;}

void Add_Edge(int x,int y) {E[cnt]=(Edge){y,El[x]};El[x]=cnt++;}
void DFS(int x,int Fa)
{
	In[x]=++tot;
	for (int i=El[x];~i;i=E[i].nxt) if (E[i].y!=Fa) DFS(E[i].y,x);
	Out[x]=tot;
}

int main()
{
	memset(El,-1,sizeof(El));
	rt=Last=New(0);
	scanf("%d%d",&n,&m);
	For(t,1,n+1)
	{
		scanf("%s",s),Len=strlen(s),Last=rt,S[t]=string(s);
		For(i,0,Len) Extend(s[i]-'a');
	}
	For(t,1,n+1)
	{
		node *x=rt;
		For(i,0,S[t].length()) x=x->go[S[t][i]-'a'];
		Ed[t]=x-Nd;
	}
	for (node *i=Nd+1;i<cur;i++) Add_Edge(i->Par-Nd,i-Nd);
	DFS(0,-1);
	For(i,0,m)
	{
		scanf("%d%d%d",&Ql,&Qr,&k);
		Q[Qc++]=(Qry){Ql-1,k,-1,i},Q[Qc++]=(Qry){Qr,k,1,i};
	}
	sort(Q,Q+Qc);
	For(i,0,Qc)
	{
		while (c<=Q[i].x)
		{
			node *x=rt;
			For(i,0,S[c].length()) x=x->go[S[c][i]-'a'],Add(In[x-Nd]);
			c++;
		}
		Ans[Q[i].ID]+=Q[i].f*(Query(Out[Ed[Q[i].k]])-Query(In[Ed[Q[i].k]]-1));
	}
	For(i,0,m) printf("%I64d\n",Ans[i]);
}