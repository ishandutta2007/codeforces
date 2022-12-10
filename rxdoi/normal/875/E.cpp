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

const int N=100000+19;

int x[N],y[N],dp[N];
int n,res,m,Ql,Qr,l,r;

int cal(int x){
	return lower_bound(y+1,y+m+1,x)-y;
}

int cov[N*4],sum[N*4];

void Cover(int x){
	cov[x]=1;
	sum[x]=0;
}
void Down(int x){
	if (cov[x]){
		cov[x]=0;
		Cover(Lsn);
		Cover(Rsn);
	}
}
void Build(int x,int L,int R){
	cov[x]=0;
	sum[x]=0;
	if (L==R) return;
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
}
void Update(int x,int L,int R,int Qx){
	if (L==R){
		sum[x]=1;
		return;
	}
	Down(x);
	Qx<=Mid?Update(Lsn,L,Mid,Qx):Update(Rsn,Mid+1,R,Qx);
	sum[x]=(sum[Lsn]+sum[Rsn]);
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Cover(x);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]+sum[Rsn];
}

bool check(int dis){
	Build(1,1,m);
	Update(1,1,m,cal(x[1]));
	Update(1,1,m,cal(x[2]));
	For(i,3,n+2+1){
		Ql=1,Qr=cal(x[i]-dis)-1;
		if (Ql<=Qr) Modify(1,1,m);
		Ql=cal(x[i]+dis+1),Qr=m;
		if (Ql<=Qr) Modify(1,1,m);
		if (sum[1]){
			Update(1,1,m,cal(x[i]));
		}
	}
	return sum[1]!=0;
}

int main(){
	n=IN();
	x[1]=IN();
	x[2]=IN();
	For(i,1,n+1) x[i+2]=IN();
	l=abs(x[1]-x[2]);
	r=int(1e9);
	For(i,1,n+2+1) y[i]=x[i];
	sort(y+1,y+n+2+1);
	m=unique(y+1,y+n+2+1)-y-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) res=mid,r=mid-1;else l=mid+1;
	}
	printf("%d\n",res);
}