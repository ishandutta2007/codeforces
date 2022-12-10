#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long LL;
typedef double Db;

const int N=4e5+19,oo=(1<<29)-1;
typedef int one[N];
vector<int> V[N];
one Dep,Pt,InPt,OutPt;
int n,Qc,Anc;

struct node *null;
struct node
{
	node *L,*R,*Fa;
	int ID,Add,Dep,Min,Max;
	
	void SetA(int v)
	{
		if (this!=null)
			Add+=v,Dep+=v,Min+=v,Max+=v;
	}
	void Down()
	{
		if (this==null) return;
		if (Add) L->SetA(Add),R->SetA(Add),Add=0;
	}
	void Update()
	{
		if (this==null) return;
		Min=Max=Dep;
		Min=min(Min,min(L->Min,R->Min));
		Max=max(Max,max(L->Max,R->Max));
	}
	void Zig()
	{
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else z->R=this;Fa=z;
		y->L=R;if (R!=null) R->Fa=y;
		R=y;y->Fa=this;y->Update();
	}
	void Zag()
	{
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else z->R=this;Fa=z;
		y->R=L;if (L!=null) L->Fa=y;
		L=y,y->Fa=this;y->Update();
	}
} Nd[N],*rt,*In[N],*Out[N];

void Splay(node *x,node *Aim)
{
	static node *S[N];node *tmp=x;int k=0;
	while (tmp->Fa!=Aim) S[++k]=tmp,tmp=tmp->Fa;S[++k]=tmp;
	while (k) S[k--]->Down();
	while (x->Fa!=Aim)
	{
		node *y=x->Fa,*z=y->Fa;
		if (y->Fa!=Aim)
			if (x==y->L) if (y==z->L) y->Zig(),x->Zig();else x->Zig(),x->Zag();
				else if (y==z->L) x->Zag(),x->Zig();else y->Zag(),x->Zag();
		else if (x==y->L) x->Zig();else x->Zag();
	}
	x->Update();if (Aim==null) rt=x;
}
node *pre(node *x)
{
	Splay(x,null);x=x->L;
	while (x->R!=null) x=x->R;
	return x;
}
node *nxt(node *x)
{
	Splay(x,null),x=x->R;
	while (x->L!=null) x=x->L;
	return x;
}

void DFS(int x)
{
	Pt[InPt[x]=++*Pt]=x;
	For(i,0,V[x].size())
	{
		int y=V[x][i];
		Dep[y]=Dep[x]+1;DFS(y);
		Pt[++*Pt]=x;
	}
	OutPt[x]=(*Pt)+1;
}
node *Build(int L,int R,node *Fa)
{
	if (L>R) return null;
	node *x=Nd+Mid;
	x->ID=Pt[Mid];
	x->Add=0;
	x->Dep=Dep[Pt[Mid]];
	x->Fa=Fa;
	x->L=Build(L,Mid-1,x);
	x->R=Build(Mid+1,R,x);
	return x->Update(),x;
}

int main()
{
	null=Nd;
	*null=(node){null,null,null,0,0,0,oo,-oo};
	n=IN(),Qc=IN();
	For(i,1,n+1)
		for (int c=IN();c--;) V[i].Pb(IN());
	DFS(1);
	rt=Build(1,*Pt,null);
	For(i,1,n+1) In[i]=Nd+InPt[i],Out[i]=Nd+OutPt[i];
	while (Qc--)
	{
		int o=IN(),x,y,k;
		if (o==1)
		{
			node *a,*b;
			x=IN(),y=IN();
			{
				Splay(In[x],null),Splay(In[y],rt);
				if (In[x]->L==In[y]) swap(x,y);
			}
			a=nxt(In[y]),b=(x==1?0x0:pre(In[x]));
			Splay(a,null);
			if (x==1) printf("%d\n",In[x]->Dep+In[y]->Dep-2*rt->L->Min);
				else Splay(b,rt),printf("%d\n",In[x]->Dep+In[y]->Dep-2*rt->L->R->Min);
		}
		if (o==2)
		{
			node *a,*b,*c;
			x=IN(),k=IN();
			Splay(In[x],null);
			int D=rt->Dep-k;
			for (node *x=rt->R;;)
			{
				if (x->L->Min<=D&&D<=x->L->Max) x=x->L,x->Down();else
					if (x->Dep==D) {Anc=x->ID;break;} else x=x->R,x->Down();
			}
			
			a=pre(In[x]),b=nxt(Out[x]);
			Splay(a,null),Splay(b,rt);
			a=rt->R->L,b=rt->R;
			a->Fa=b->L=null;
			b->Update(),rt->Update();
			a->SetA(-(k-1));

			node *prt=rt;
			Splay(Out[x],null);a=Out[x];
			if (Anc==1)
			{
				node *x=prt;
				while (x->R!=null) x=x->R;
				Splay(x,null);
				rt->R=a,a->Fa=rt,rt->Update();
			} else
			{
				Splay(pre(Out[Anc]),null);
				b=rt->R,b->Fa=rt->R=null,rt->Update();
				rt->R=a,a->Fa=rt;
				a->R=b,b->Fa=a;
				a->Update(),rt->Update();
			}

			Out[x]->ID=Anc;
		}
		if (o==3)
		{
			k=IN();
			for (node *x=rt;;)
				if (x->R->Min<=k&&k<=x->R->Max) x=x->R,x->Down();else
					if (x->Dep==k) {printf("%d\n",x->ID);break;} else x=x->L,x->Down();
		}
	}
}