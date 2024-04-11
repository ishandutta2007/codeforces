#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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

const int N=1000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

const int I6=Pow(6,p-2);

int fac[N],inv[N],Inv[N],val[N];
int ans;
ll n;

inline int S1(int x){
	return 1ll*x*(x+1)/2%p;
}
inline int S2(int x){
	return 1ll*x*(x+1)%p*(2ll*x+1)%p*I6%p;
}
inline int S(ll x){
	x%=p;
	return (1ll*(n+1)%p*S1(x)-S2(x)+p)%p;
}
inline int cal(ll w){
	return (S(n)-S(w-1)+p)%p;
}
int work(int x,int n){
	int pre[N],suf[N];
	pre[0]=suf[n+1]=1;
	for (int i=1;i<=n;i++) pre[i]=1ll*pre[i-1]*(x-i+p)%p;
	for (int i=n;i>=1;i--) suf[i]=1ll*suf[i+1]*(x-i+p)%p;
	int ans=0;
	For(i,1,n+1) ans=(ans+1ll*val[i]*pre[i-1]%p*suf[i+1]%p*inv[i-1]%p*Inv[n-i])%p;
	return ans;
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	For(i,0,N) Inv[i]=(i&1?p-inv[i]:inv[i]);
	cin>>n;
	for (int x=1;1ll*x*x<=n;x++){
		int lim=int(sqrt(n-1ll*x*x));
		int top=min(10,lim);
		if (lim>0){
			For(y,1,top+1) val[y]=cal(1ll*x*x+1ll*y*y);
			For(y,1,top+1) val[y]=(val[y]+val[y-1])%p;
			if (lim<=top){
				ans=(ans+val[lim])%p;
			} else{
				ans=(ans+work(lim,top))%p;
			}
		}
		ans=(ans+cal(1ll*x*x))%p;
	}
	ans=4ll*ans%p;
	ans=(ans+1ll*(p+1)/2*(S1(n%p)+S2(n%p)))%p;
	printf("%d\n",ans);
}