#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int P=998244353;
const int G=3;
const int N=(1<<18);
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int w[2][N*2+5];
int rev[N*2+5];
int fac[N*2+5],inv[N*2+5];
int C(int a,int b){
	if(a<b)return 0;
	return (fac[a]*1ll*inv[b]%P)*1ll*inv[a-b]%P;
}
void init(int n){
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv[n]=Pow(fac[n],P-2);
	per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;

	rep(i,0,n-1){
		int x=i;int y=0;
		for(int k=1;k<n;k<<=1,x>>=1)(y<<=1)|=(x&1);
		rev[i]=y;
	}
	w[0][0]=w[1][0]=1;
	int V=Pow(G,(P-1)/n);
	int VV=Pow(V,P-2);
	rep(i,1,n){
		w[0][i]=w[0][i-1]*1ll*V%P;
		w[1][i]=w[1][i-1]*1ll*VV%P;
	}
}
void fft(int *a,int n,int f){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(int i=1;i<n;i<<=1)
    for(int j=0,t=n/(i<<1);j<n;j+=(i<<1))
    for(int k=0,l=0;k<i;k++,l+=t){
        int x=a[k+j],y=(LL)a[k+j+i]*w[f][l]%P;
        a[k+j]=(x+y)%P;
        a[k+j+i]=(x-y+P)%P;
    }
    int Rev=Pow(n,P-2);
    if(f) for(int i=0;i<n;i++) a[i]=(LL)a[i]*Rev%P;
}
int v[N*2+5];
int a[N*2+5],b[N*2+5];
int n;
LL M;
void work1(){
	rep(i,0,n-1){
		a[i]=inv[i];
	}
	rep(i,0,n-1){
		b[n-i-1]=v[i]*1ll*fac[i]%P;
	}
	fft(a,N,0);
	fft(b,N,0);
	rep(i,0,N-1)a[i]=a[i]*1ll*b[i]%P;
	fft(a,N,1);
	rep(i,0,n-1){
		v[i]=a[i]*1ll*inv[n-i-1]%P;
	}
}
void work2(){
	rep(i,0,n-1){
		v[i]=Pow(Pow(n-i,P-2),(int)(M%(P-1)))*1ll*v[i]%P;
	}
}
void work3(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	rep(i,0,n-1){
		a[i]=v[i]*1ll*fac[n-i-1]%P;
		if((i+n+1)&1)a[i]=(P-a[i])%P;
	}
	rep(i,0,n-1)b[i]=inv[i];
	fft(a,N,0);
	fft(b,N,0);
	rep(i,0,N-1)a[i]=a[i]*1ll*b[i]%P;
	fft(a,N,1);
	rep(i,0,n-1){
		v[i]=a[n-1-i]*1ll*inv[i]%P;
		if(i&1)v[i]=(P-v[i])%P;
	}
}
int main(){
	scanf("%d%lld",&n,&M);
	init(N);
	++n;
	rep(i,0,n-1)scanf("%d",&v[i]);
	work1();
	//rep(i,0,n-1)printf("%d ",v[i]);puts("");
	work2();
	//rep(i,0,n-1)printf("%d ",v[i]);puts("");
	work3();
	rep(i,0,n-1)printf("%d ",v[i]);puts("");
	return 0;
}