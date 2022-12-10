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
#define pb push_back
#define mp make_pair
#define fi first
#define se second

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

const int N=2e5+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int fac[N],inv[N],f[N],g[N],w[N],res1[N],res2[N];
int n,m,h,ans1,ans2,top;

int C(ll n,ll m){
	if (n<m) return 0;
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	n=IN(),m=IN(),h=IN();
	f[0]=(n==0);
	w[0]=g[0]=(m==0);
	For(i,1,n+1) f[i]=1ll*C(n-1,i-1);
	For(i,1,m+1) w[i]=1ll*C(m-1,i-1);
	For(i,1,m+1) g[i]=1ll*C(m-1ll*i*h-1,i-1);
	top=max(n,m)+1;
	For(i,0,top+1){
		ans1=(ans1+2ll*f[i]*g[i])%p;
		if (i) ans1=(ans1+1ll*f[i]*g[i-1])%p;
		ans1=(ans1+1ll*f[i]*g[i+1])%p;
		ans2=(ans2+2ll*f[i]*w[i])%p;
		if (i) ans2=(ans2+1ll*f[i]*w[i-1])%p;
		ans2=(ans2+1ll*f[i]*w[i+1])%p;
	}
	printf("%d\n",1ll*ans1*Pow(ans2,p-2)%p);
}