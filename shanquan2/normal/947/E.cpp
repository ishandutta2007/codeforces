#include<cstdio>
#include<algorithm>
#define M 998244353
using namespace std;

typedef long long ll;
int K,a[1<<18],b[1<<18],c[1<<18],d[1<<18],fc[100005],fi[100005],w[2][(1<<18)+1];
int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);tmp=(ll)tmp*tmp%M;
	return (t&1)?(ll)tmp*x%M:tmp;
}
inline void fft(int x[],int k,int v){
	for(int i=0,j=0;i<k;i++){
		if(i>j)swap(x[i],x[j]);
		for(int l=k>>1;(j^=l)<l;l>>=1);
	}
	for(int i=2;i<=k;i<<=1)
		for(int j=0;j<k;j+=i)
			for(int l=0;l<i>>1;l++){
				int t=(ll)x[j+l+(i>>1)]*w[v][K/i*l]%M;
				x[j+l+(i>>1)]=(x[j+l]-t+M)%M;
				x[j+l]=(x[j+l]+t)%M;
			}
	if(v){
		int ik=fexp(k,M-2);
		for(int i=0;i<k;i++)x[i]=(ll)x[i]*ik%M;
	}
}
long long m;
int main(){
	int n;scanf("%d",&n);n++;
	for(K=1;K<=(n+1<<1);K<<=1);
	w[0][0]=1;
	int g=fexp(3,(M-1)/K);
	for(int i=1;i<=K;i++)w[0][i]=(ll)w[0][i-1]*g%M;
	for(int i=0;i<=K;i++)w[1][i]=w[0][K-i];
	fc[0]=1;
	for(int i=1;i<=n;i++)fc[i]=(ll)fc[i-1]*i%M;
	fi[n]=fexp(fc[n],M-2);
	for(int i=n-1;i>=0;i--)fi[i]=1ll*fi[i+1]*(i+1)%M;
	scanf("%I64d",&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)a[i]=1ll*a[i]*fc[i-1]%M;
	for(int i=0;i<n;i++)b[i]=fi[n-i-1];
	fft(a,K,0);fft(b,K,0);
	for(int i=0;i<K;i++)a[i]=1ll*a[i]*b[i]%M;
	fft(a,K,1);
	for(int i=1;i<=n;i++)c[i]=1ll*fi[n-i]*a[2*n-i]%M;
//	for(int i=1;i<=n;i++)printf("%d ",c[i]);printf("\n");
	for(int i=1;i<=n;i++)c[i]=1ll*c[i]*fexp(n-i+1,-m%(M-1)+(M-1))%M;
	for(int i=1;i<=n;i++){
		c[i]=1ll*c[i]*fc[n-i]%M;
		if(i&1)c[i]=M-c[i];
	}
	for(int i=0;i<n;i++)d[i]=fi[i];
	fft(c,K,0);fft(d,K,0);
	for(int i=0;i<K;i++)c[i]=1ll*c[i]*d[i]%M;
	fft(c,K,1);
	for(int i=1;i<=n;i++){
		a[i]=1ll*fi[i-1]*c[n-i+1]%M;
		if((n+i+1)%2)a[i]=(M-a[i])%M;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
	return 0;
}