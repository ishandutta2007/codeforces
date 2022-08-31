#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
#define int64 LL 
typedef double db;
const int N=(1<<20)+5;LL p;
int n;
int64 mul(int64 a,int64 b){
	return (a*b-(int64)((long double)a/p*b)*p)%p;
}
int64 Pow(int64 x,int64 y){
	int64 res=1;
	while(y){
		if(y&1)res=mul(res,x);
		x=mul(x,x);
		y/=2;
	}
	return res;
}
inline void FWT(LL *a){
	for(int i=1;i<n;i<<=1)
	for(int j=0;j<n;j+=(i<<1))
	for(int k=0;k<i;k++){
		LL x=a[j+k+i];LL y=a[j+k];
		a[j+k+i]=(y-x);if(a[j+k+i]<0)a[j+k+i]+=p;
		a[j+k]=(x+y);if(a[j+k]>=p)a[j+k]-=p;
	}
}
void DFT(int64 a[],int flag){
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=i<<1)
			for(int k=0;k<i;++k){
				int64 u=a[j+k],v=a[i+j+k];
				a[j+k]=(u+v)%p; //if(a[j+k]>=p)a[j+k]-=p;
				a[i+j+k]=(u-v)%p; if(a[i+j+k]<0)a[i+j+k]+=p;
			}
	if(flag==-1){
		rep(i,0,n-1)a[i]/=n;
	}
}
inline LL read(LL &x){
	x=0;char q=getchar();
	while(!(q<='9'&&q>='0'))q=getchar();
	while(q<='9'&&q>='0')x*=10ll,x+=q-48,q=getchar();
}
int m;LL t;int b[25];LL e[N];int num[N];LL c[N];
int main(){
	scanf("%d%I64d%I64d",&m,&t,&p);n=(1<<m);p=p*1ll*n;
	rep(i,0,n-1){read(e[i]);}
	rep(i,0,m)scanf("%d",&b[i]);
	c[0]=b[0];
	rep(i,1,n-1){
		num[i]=num[i/2]+(i&1);
		c[i]=b[num[i]];
	}
	DFT(c,1);
	rep(i,0,n-1)c[i]=Pow(c[i],t);
	DFT(e,1);
	rep(i,0,n-1)e[i]=mul(e[i],c[i]);
	DFT(e,-1);
	rep(i,0,n-1){
		if(e[i]<0)e[i]+=p;
		printf("%I64d\n",e[i]);
	}
	return 0;
}