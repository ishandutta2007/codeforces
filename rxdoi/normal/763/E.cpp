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

const int N=1000000+19,oo=(1<<30)-1;

struct QType{
	int ID,L,R;
	bool operator < (const QType& B) const {return R<B.R;}
} Q[N];
struct Edge{
	int x,y;
	bool operator < (const Edge &B) const {return y<B.y;}
} E[N];
int Ans[N],n,m,Qc,tot,j;

int cmp(int a,int b){
	if (a==oo) return b;
	if (b==oo) return a;
	return E[a].x<E[b].x?a:b;
}

struct node *null;
struct node
{
	node *L,*R,*Fa;
	int rev,ID,Min;

	bool Top() {return Fa==null||Fa->L!=this&&Fa->R!=this;}
	void Setrev() {rev^=1;swap(L,R);}
	void Down(){
		if (rev) L->Setrev(),R->Setrev(),rev=0;
	}
	void Update(){
		Min=cmp(cmp(L->Min,R->Min),ID);
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
} Nd[N],*cur,*Pe[N],*P[N];

void Splay(node *x)
{
	static node *S[N];node *tmp=x;int k=0;
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
void Evert(node *x) {Access(x)->Setrev();}
node *Root(node *x)
{
	Access(x);Splay(x);
	while (x->L!=null) x=x->L,x->Down();
	return x;
}
void Link(node *x,node *y) {Evert(x),Splay(x);x->Fa=y;}
void Cut(node *x,node *y)
{
	Access(x),Splay(y);
	if (y->Fa==x) y->Fa=null;else Access(y),Splay(x),x->Fa=null;
}
void New(node *&x,int ID)
{
	x=++cur;
	*x=(node){null,null,null,0,ID,ID};
}

int C[N];
void Add(int x,int v){
	for (;x<=n;x+=x&-x) C[x]+=v;
}
int Query(int x){
	int Ans=0;
	for (;x;x-=x&-x) Ans+=C[x];
	return Ans;
}

int num;

int main()
{
	null=Nd;
	*null=(node){null,null,null,0,oo,oo};
	cur=Nd;
	n=IN(),IN();
	m=IN();
	For(i,1,m+1){
		E[i]=(Edge){IN(),IN()};
		if (E[i].x>E[i].y) swap(E[i].x,E[i].y);
	}
	sort(E+1,E+m+1);
	Qc=IN();
	For(i,1,Qc+1){
		Q[i]=(QType){i,IN(),IN()};
	}
	sort(Q+1,Q+Qc+1);
	For(i,1,n+1) New(P[i],oo);
	For(i,1,m+1) New(Pe[i],i);
	j=1;
	For(i,1,Qc+1){
		for (;j<=m&&E[j].y<=Q[i].R;j++){
			int x=E[j].x,y=E[j].y,t;
			if (x!=y){
				if (Root(P[x])!=Root(P[y])){
					Link(P[x],Pe[j]);
					Link(P[y],Pe[j]);
					Add(E[j].x,1);
					num++;
				} else{
					Evert(P[x]),t=Access(P[y])->Min;
					if (E[t].x>E[j].x) continue;
					Cut(P[E[t].x],Pe[t]);
					Cut(P[E[t].y],Pe[t]);
					Add(E[t].x,-1);
					Link(P[x],Pe[j]);
					Link(P[y],Pe[j]);
					Add(E[j].x,1);
				}
			}
		}
		Ans[Q[i].ID]=Q[i].R-Q[i].L+1-(num-Query(Q[i].L-1));
	}

	For(i,1,Qc+1) printf("%d\n",Ans[i]);
}