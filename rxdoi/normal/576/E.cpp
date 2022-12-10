#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=500000+19,Size=N*3,oo=(1<<30)-1;
struct Edge {int x,y,c,T;} E[N];
struct QType {int x,y,nxt;} Q[N];
int Last[N];
int n,m,k,Qc;

//LCT
struct node *null;
struct node
{
	node *L,*R,*Fa;
	int rev,Sum,Min,key,Pos;

	bool Top() {return Fa==null||Fa->L!=this&&Fa->R!=this;}
	void Setrev() {swap(L,R),rev^=1;}
	void Down()
	{
		if (rev) L->Setrev(),R->Setrev(),rev=0;
	}
	void Update()
	{
		if (this==null) return;
		Sum=L->Sum+R->Sum+key;
		Min=Pos;
		if (E[L->Min].T<E[Min].T) Min=L->Min;
		if (E[R->Min].T<E[Min].T) Min=R->Min;
	}
	void Zig()
	{
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->L=R;if (R!=null) R->Fa=y;
		R=y;y->Fa=this;y->Update();
	}
	void Zag()
	{
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->R=L;if (L!=null) L->Fa=y;
		L=y;y->Fa=this;y->Update();
	}
} Nd[Size],*Pos[51][N],*Pe[N],*cur=Nd;

void Splay(node *x)
{
	static node *S[N+N];
	node *tmp=x;int k=0;
	while (!tmp->Top()) S[++k]=tmp,tmp=tmp->Fa;S[++k]=tmp;
	while (k) S[k--]->Down();
	while (!x->Top())
	{
		node *y=x->Fa,*z=y->Fa;
		if (!y->Top())
			if (x==y->L) if (y==z->L) y->Zig(),x->Zig();else x->Zig(),x->Zag();
				else if (y==z->L) x->Zag(),x->Zig();else y->Zag(),x->Zag();
		else if (x==y->L) x->Zig();else x->Zag();
	}
	x->Update();
}
node *Access(node *x)
{
	node *y;
	for (y=null;x!=null;y=x,x=x->Fa) Splay(x),x->R=y,x->Update();
	return y;
}
node *Root(node *x)
{
	Access(x),Splay(x);
	while (x->L!=null) x=x->L,x->Down();
	return x;
}
void Evert(node *x) {Access(x)->Setrev();}
void Link(node *x,node *y) {Evert(x),Splay(x),x->Fa=y;}
void Cut(node *x,node *y)
{
	Access(x),Splay(y);
	if (y->Fa==x) y->Fa=null;else Access(y),Splay(x),x->Fa=null;
}
int Query(int k,int Ix,int Iy)
{
	node *x,*y;
	if (!(x=Pos[k][Ix])||!(y=Pos[k][Iy])) return 1;
	if (Root(x)!=Root(y)) return 1;
	Evert(x);
	return Evert(x),!(Access(y)->Sum&1);
}
void New_it(node *&x,int ID)
{
	if (x) return;
	x=++cur;*x=(node){null,null,null,0,!ID,ID,!ID,ID};
}

int main()
{
	null=Nd;*null=(node){null,null,null,0,0,0,0,0};
	E[0].T=oo;

	n=IN(),m=IN(),k=IN(),Qc=IN();
	For(i,1,m+1) E[i]=(Edge){IN(),IN(),0,0},New_it(Pe[i],i);
	For(i,1,Qc+1) Q[i]=(QType){IN(),IN(),0};

	For(i,1,m+1) Last[i]=Qc+1;
	for (int i=Qc;i;i--) Q[i].nxt=Last[Q[i].x],Last[Q[i].x]=i;
	For(i,1,m+1) E[i].T=Last[i];

	For(i,1,Qc+1)
	{
		int ID=Q[i].x,c=E[ID].c,k=Q[i].y,x=E[ID].x,y=E[ID].y;
		E[ID].T=Q[i].nxt;
		if (Query(k,x,y))
		{
			puts("YES");
			E[ID].c=k;
			if (c&&Root(Pos[c][x])==Root(Pos[c][y]))
				Cut(Pos[c][x],Pe[ID]),Cut(Pos[c][y],Pe[ID]);
			node *&Px=Pos[k][x],*&Py=Pos[k][y];
			New_it(Px,0),New_it(Py,0);
			if (Root(Px)!=Root(Py))
			{
				Link(Px,Pe[ID]),Link(Py,Pe[ID]);
			} else
			{
				int t;
				Evert(Px),t=Access(Py)->Min;
				if (E[t].T<E[ID].T)
				{
					Cut(Pos[k][E[t].x],Pe[t]),Cut(Pos[k][E[t].y],Pe[t]);
					Link(Px,Pe[ID]),Link(Py,Pe[ID]);
				}
			}
		} else
		{
			puts("NO");
			if (!E[ID].c) continue;
			node *&Px=Pos[E[ID].c][x],*&Py=Pos[E[ID].c][y];
			int t;
			Evert(Px),t=Access(Py)->Min;
			if (E[t].T<E[ID].T)
			{
				Cut(Pos[E[ID].c][E[t].x],Pe[t]),Cut(Pos[E[ID].c][E[t].y],Pe[t]);
				Link(Px,Pe[ID]),Link(Py,Pe[ID]);
			}
		}
	}
}