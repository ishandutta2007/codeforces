#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=500000+19;

struct node{
	int a,b,c;
	bool operator < (const node &B) const{
		return a<B.a;
	}
} A[N];
int mxb[N],mxc[N];
int n,p,q,r,c;
ll res;

int mn[N*4],cov[N*4];
ll sum[N*4];
int Ql,Qr,Qv,pos;

void Cov(int x,int L,int R,int v){
	mn[x]=v;
	cov[x]=v;
	sum[x]=1ll*v*(R-L+1);
}
void Down(int x,int L,int R){
	if (cov[x]){
		Cov(Lsn,L,Mid,cov[x]);
		Cov(Rsn,Mid+1,R,cov[x]);
		cov[x]=0;
	}
}
void Build(int x,int L,int R){
	if (L==R){
		mn[x]=sum[x]=1;
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
	sum[x]=sum[Lsn]+sum[Rsn];
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Cov(x,L,R,Qv);
		return;
	}
	Down(x,L,R);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
	sum[x]=sum[Lsn]+sum[Rsn];
}
ll Qsum(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return sum[x];
	Down(x,L,R);
	ll res=0;
	if (Ql<=Mid) res+=Qsum(Lsn,L,Mid);
	if (Qr>Mid) res+=Qsum(Rsn,Mid+1,R);
	return res;
}
int Qmin2(int x,int L,int R){
	if (L==R) return L;
	Down(x,L,R);
	if (mn[Lsn]<=Qv) return Qmin2(Lsn,L,Mid);
	return Qmin2(Rsn,Mid+1,R);
}
void Qmin(int x,int L,int R){
	if (~pos) return;
	if (Ql<=L&&R<=Qr){
		if (mn[x]<=Qv) pos=Qmin2(x,L,R);
		return;
	}
	Down(x,L,R);
	if (Ql<=Mid) Qmin(Lsn,L,Mid);
	if (Qr>Mid) Qmin(Rsn,Mid+1,R);
}

void gao(int x,int y){
	pos=-1;
	Ql=1,Qr=x,Qv=y;
	Qmin(1,1,q);
	if (pos==-1) return;
	Ql=pos,Qr=x,Qv=y;
	Modify(1,1,q);
}
ll qry(int x,int y){
	if (x>q||y>r) return 0;
	pos=-1;
	Ql=x,Qr=q,Qv=y;
	Qmin(1,1,q);
	if (pos==-1) pos=q+1;
	ll res=0;
	res+=1ll*(r-y+1)*(q-pos+1);
	Ql=x,Qr=pos-1;
	if (Ql<=Qr){
		res+=1ll*(r+1)*(Qr-Ql+1);
		res-=Qsum(1,1,q);
	}
	return res;
}

int main(){
	//freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	n=IN(),p=IN(),q=IN(),r=IN();
	For(i,1,n+1){
		A[i]=(node){IN(),IN(),IN()};
	}
	sort(A+1,A+n+1);
	for (int i=n;i;i--){
		mxb[i]=max(mxb[i+1],A[i].b);
		mxc[i]=max(mxc[i+1],A[i].c);
	}
	Build(1,1,q);
	c=1;
	for (int u=1;u<=p;u++){
		for (;c<=n&&A[c].a<u;c++){
			gao(A[c].b,A[c].c+1);
		}
		res+=qry(mxb[c]+1,mxc[c]+1);
	}
	cout<<res<<endl;
}