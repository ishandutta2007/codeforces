#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 4096
#define P 7340033
#define G 3

int rn,r[max_N],w[2][max_N];

inline int qpow(int x,int k){
	int res=1;
	if(k<0)k+=P-1;
	for(;k;x=1ll*x*x%P,k>>=1)if(k&1)res=1ll*res*x%P;
	return res;	
}

inline void init_fft(){
	int n=max_N;
	rn=qpow(n,-1);
	int g=qpow(G,(P-1)/n);
	w[0][0]=w[1][0]=1;
	for(int i=1;i<n;++i)w[0][i]=1ll*w[0][i-1]*g%P;
	for(int i=1;i<n;++i)w[1][i]=w[0][n-i];
	for(int i=1;i<n;++i)r[i]=(r[i>>1]>>1)^((i&1)<<11);
}

inline void fft(int*a,int t){
	int n=max_N;
	for(int i=1;i<n;++i)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<(i>>1);++k){
				int tmp=1ll*w[t][n/i*k]*a[(i>>1)+j+k]%P;
				a[(i>>1)+j+k]=(a[j+k]-tmp+P)%P;
				a[j+k]=(a[j+k]+tmp)%P;
			}
	if(t)for(int i=0;i<n;++i)a[i]=1ll*a[i]*rn%P;
}

int q,n,k,f[33][max_N],a[max_N];

inline void init(){
	int n=max_N;
	f[0][0]=1;
	for(int i=1;i<=30;++i){
		for(int j=0;j<n;++j)a[j]=i<(n>>2)?f[i-1][j]:0;
		fft(a,0);
		for(int j=0;j<n;++j)a[j]=1ll*a[j]*a[j]%P,a[j]=1ll*a[j]*a[j]%P;
		fft(a,1);
		f[i][0]=1;
		for(int j=1;j<(n>>2);++j)f[i][j]=a[j-1];
	}
}

int main(){
	init_fft();
	init();
	q=gint();
	while(q--){
		n=gint(),k=gint();
		int x=0;
		while(n>1&&(n&1))n>>=1,++x;
		printf("%d\n",f[x][k]);
	}
	return 0;
}