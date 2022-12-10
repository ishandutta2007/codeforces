#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (y=E[i].y)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define Mid (L+R>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;
const int Top=10000000;

struct node *null;
struct node{
	node *L,*R;
	int sum;
} Nd[Top],*cur=Nd+1,*rt[N],*Rt[N];
vector<node*> V1,V2,S1,S2;
int Qx,Qv,Ql,Qr;

node *Modify(node *x,int L,int R){
	node *y=cur++;
	y->sum=x->sum+1;
	if (L==R) return y;
	if (Qx<=Mid){
		y->L=Modify(x->L,L,Mid);
		y->R=x->R;
	} else{
		y->L=x->L;
		y->R=Modify(x->R,Mid+1,R);
	}
	return y;
}
int Qrymx(int L,int R){
	if (L==R) return L;
	int tmp=0;
	for (auto i:V1) tmp+=i->R->sum;
	for (auto i:V2) tmp-=i->R->sum;
	assert(tmp>=0);
	if (tmp){
		for (auto &i:V1) i=i->R;
		for (auto &i:V2) i=i->R;
		return Qrymx(Mid+1,R);
	} else{
		for (auto &i:V1) i=i->L;
		for (auto &i:V2) i=i->L;
		return Qrymx(L,Mid);
	}
}
int Querymx(int L,int R){
	if (Ql<=L&&R<=Qr){
		int tmp=0;
		for (auto i:V1) tmp+=i->sum;
		for (auto i:V2) tmp-=i->sum;
		assert(tmp>=0);
		if (!tmp) return -1;
		return Qrymx(L,R);
	}
	int tmp;
	vector<node*> T1=V1,T2=V2;
	for (auto &i:V1) i=i->R;
	for (auto &i:V2) i=i->R;
	if (Qr>Mid&&~(tmp=Querymx(Mid+1,R))) return tmp;
	V1=T1,V2=T2;
	for (auto &i:V1) i=i->L;
	for (auto &i:V2) i=i->L;
	if (Ql<=Mid&&~(tmp=Querymx(L,Mid))) return tmp;
	return -1;
}
int Qrymn(int L,int R){
	if (L==R) return L;
	int tmp=0;
	for (auto i:V1) tmp+=i->L->sum;
	for (auto i:V2) tmp-=i->L->sum;
	assert(tmp>=0);
	if (tmp){
		for (auto &i:V1) i=i->L;
		for (auto &i:V2) i=i->L;
		return Qrymn(L,Mid);
	} else{
		for (auto &i:V1) i=i->R;
		for (auto &i:V2) i=i->R;
		return Qrymn(Mid+1,R);
	}
}
int Querymn(int L,int R){
	if (Ql<=L&&R<=Qr){
		int tmp=0;
		for (auto i:V1) tmp+=i->sum;
		for (auto i:V2) tmp-=i->sum;
		assert(tmp>=0);
		if (!tmp) return -1;
		return Qrymn(L,R);
	}
	int tmp;
	vector<node*> T1=V1,T2=V2;
	for (auto &i:V1) i=i->L;
	for (auto &i:V2) i=i->L;
	if (Ql<=Mid&&~(tmp=Querymn(L,Mid))) return tmp;
	V1=T1,V2=T2;
	for (auto &i:V1) i=i->R;
	for (auto &i:V2) i=i->R;
	if (Qr>Mid&&~(tmp=Querymn(Mid+1,R))) return tmp;
	return -1;
}

struct Edge{
	int y,nxt;
} E[N];
int las[N],I[N],O[N],sz[N],res[N],pl[N];
int n,cnt,r,tot,x,y;

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void dfs(int x){
	I[x]=++tot;
	pl[tot]=x;
	sz[x]=1;
	Rep(x){
		dfs(y);
		sz[x]+=sz[y];
	}
	O[x]=tot;
}
void Dfs(int x,int fa){
	Qx=sz[x];
	Rt[x]=Modify(Rt[x],1,n);
	Vi V;
	Rep(x) V.pb(sz[y]);
	if (~fa) V.pb(n-sz[x]);
	sort(V.begin(),V.end(),greater<int>());
	if (V.size()==1){
		res[x]=V[0];
	} else{
		int mx=V[0],mn=V.back(),sc=V[1],tmp=mx,z,val;
		if (mx==n-sz[x]){
			S1.clear();S2.clear();
			S1.pb(Rt[fa]);
			V1=S1,V2=S2;
			Ql=1,Qr=(mx-mn+2*sz[x])/2;
			if (Ql<=Qr&&~(val=Querymx(1,n))){
				tmp=min(tmp,mx-val+sz[x]);
			}
			V1=S1,V2=S2;
			Ql=(mx-mn+2*sz[x])/2+1,Qr=n;
			if (Ql<=Qr&&~(val=Querymn(1,n))){
				tmp=min(tmp,mn+val-sz[x]);
			}
			S1.clear();S2.clear();
			S1.pb(rt[I[x]-1]);
			S1.pb(rt[n]);
			S2.pb(Rt[fa]);
			S2.pb(rt[O[x]]);
		} else{
			Rep(x) if (sz[y]==mx) z=y;
			S1.clear();S2.clear();
			S1.pb(rt[O[z]]);
			S2.pb(rt[I[z]-1]);
		}
		V1=S1,V2=S2;
		Ql=1,Qr=(mx-mn)/2;
		if (Ql<=Qr&&~(val=Querymx(1,n))){
			tmp=min(tmp,mx-val);
		}
		V1=S1,V2=S2;
		Ql=(mx-mn)/2+1,Qr=n;
		if (Ql<=Qr&&~(val=Querymn(1,n))){
			tmp=min(tmp,mn+val);
		}
		res[x]=max(tmp,sc);
	}
	Rep(x){
		Rt[y]=Rt[x];
		Dfs(y,x);
	}
}

int main(){
	memset(las,-1,sizeof(las));
	null=Nd;
	*null=(node){null,null,0};
	n=IN();
	if (n==1){
		puts("0");
		return 0;
	}
	For(i,1,n+1){
		x=IN(),y=IN();
		if (x) Add_Edge(x,y);else r=y;
	}
	dfs(r);
	rt[0]=null;
	For(i,1,n+1){
		Qx=sz[pl[i]];
		rt[i]=Modify(rt[i-1],1,n);
	}
	Rt[r]=null;
	Dfs(r,-1);
	For(i,1,n+1) printf("%d\n",res[i]);
}