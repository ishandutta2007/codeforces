#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lf else if

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

const int p=998244353;
const int N=1e6+19;
const int M=4*N;

int Pow(int a,ll b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int fac[N],inv[N],pw3[N];
int n,res,tmp,c;

int C(int n,int m){
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	pw3[0]=1;
	For(i,1,N) pw3[i]=3ll*pw3[i-1]%p;
	n=IN();
	For(i,0,n+1){
		tmp=1ll*C(n,i)*Pow(3,1ll*n*(n-i))%p;
		tmp=2ll*tmp*pw3[i]%p;
		if (i&1) res=(res-tmp+p)%p;else res=(res+tmp)%p;
	}
	res=(res-Pow(3,1ll*n*n)+p)%p;
	For(i,1,n+1){
		int val=Pow(Pow(3,n-i)-1+p,n);
		val=(val-Pow(3,1ll*n*(n-i))+p)%p;
		val=3ll*val*C(n,i)%p;
		if (i&1) res=(res-val+p)%p;else res=(res+val)%p;
	}
	res=(Pow(3,1ll*n*n)-res+p)%p;
	cout<<res<<endl;
}