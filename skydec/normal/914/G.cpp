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
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
inline void FWT(int *A,int f,int N){
    int p2=Pow(2,P-2);
    for(int i=1;i<N;i<<=1)
    for(int j=0;j<N;j+=(i<<1))
    for(int k=0;k<i;k++){
        int x0=A[j+k];int x1=A[i+j+k];
        if(f==0){
            A[j+k]=(x0-x1+P)%P;
            A[i+j+k]=(x0+x1)%P;
        }
        else{
            A[j+k]=(x0+x1)*1ll*p2%P;
            A[i+j+k]=(x1-x0)*1ll*p2%P;
            if(A[i+j+k]<0)A[i+j+k]+=P;
        }
    }
}
const int N=1<<17;
int cnt[N];
int ss;
int n=17;
int f[N][18];
int bit[N];
int gt[18];
int p1[N];
int p2[N];

int p3[N];

int fib[N];
void tr(int *a){
	rep(i,0,n-1)per(S,(1<<n)-1,0)if(!(S&(1<<i)))a[S]=(a[S]+a[S^(1<<i)])%P;
}
void ntr(int *a){
	per(i,n-1,0)rep(S,0,(1<<n)-1)if(!(S&(1<<i)))a[S]=(a[S]+P-a[S^(1<<i)])%P;
}
int main(){
	scanf("%d",&ss);
	rep(i,1,(1<<n)-1)bit[i]=bit[i>>1]+(i&1);
	fib[0]=0;fib[1]=1;
	rep(i,2,(1<<n)-1)fib[i]=(fib[i-1]+fib[i-2])%P;
	while(ss--){
		int x;scanf("%d",&x);
		cnt[x]++;
	}
	rep(i,0,(1<<n)-1){
		f[i][bit[i]]=cnt[i];
	}
	rep(i,0,n-1)rep(S,0,(1<<n)-1)if(S&(1<<i))rep(j,0,n)f[S][j]=(f[S][j]+f[S^(1<<i)][j])%P;
	rep(S,0,(1<<n)-1){
		memset(gt,0,sizeof gt);
		rep(i,0,n)rep(j,0,n-i)gt[i+j]=(gt[i+j]+f[S][i]*1ll*f[S][j])%P;
		rep(i,0,n)f[S][i]=gt[i];
	}
	per(i,n-1,0)per(S,(1<<n)-1,0)if(S&(1<<i))rep(j,0,n)f[S][j]=(f[S][j]+P-f[S^(1<<i)][j])%P;
	rep(S,0,(1<<n)-1)p1[S]=f[S][bit[S]]*1ll*fib[S]%P;
	rep(S,0,(1<<n)-1)p2[S]=cnt[S]*1ll*fib[S]%P;

	rep(S,0,(1<<n)-1)p3[S]=cnt[S];

	FWT(p3,0,1<<n);
	rep(S,0,(1<<n)-1)p3[S]=p3[S]*1ll*p3[S]%P;
	FWT(p3,1,1<<n);
	rep(S,0,(1<<n)-1)p3[S]=p3[S]*1ll*fib[S]%P;

	tr(p1);tr(p2);tr(p3);
	rep(i,0,(1<<n)-1)p1[i]=(p1[i]*1ll*p2[i]%P)*1ll*p3[i]%P;
	ntr(p1);
	int ans=0;
	rep(i,0,n-1)ans=(ans+p1[1<<i])%P;
	printf("%d\n",ans);
	return 0;
}