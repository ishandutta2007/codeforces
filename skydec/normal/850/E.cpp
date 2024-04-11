#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=1<<20;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n;
int f[N];
char a[(N)+100];
void fft(int *A,int n){
	rep(i,0,n-1)rep(j,0,(1<<n)-1)if(j&(1<<i)){
		int x=A[j^(1<<i)];
		int y=A[j];
		A[j^(1<<i)]=(x+y)%P;
		A[j]=(x+P-y)%P;
	}
}
void dft(int *A,int n){
	rep(i,0,n-1)rep(j,0,(1<<n)-1)if(j&(1<<i)){
		int x=A[j^(1<<i)];
		int y=A[j];
		A[j^(1<<i)]=(x+y)*1ll*((P+1)/2)%P;
		A[j]=(x+P-y)*1ll*((P+1)/2)%P;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	rep(i,0,(1<<n)-1)f[i]=(a[i]-'0');
	fft(f,n);
	rep(i,0,(1<<n)-1)f[i]=f[i]*1ll*f[i]%P;
	dft(f,n);
	int ans=0;
	rep(i,0,(1<<n)-1){
		int w=f[i];
		rep(j,0,n-1)if(!(i&(1<<j)))w=w*2ll%P;
		ans=(ans+w)%P;
	}
	printf("%d\n",ans*3ll%P);
	return 0;
}