#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+99;

int n,t,k;
ll ans=0,mod=998244353;

//math
ll fac[N],ifac[N],e,p;
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int main(){
	make_fac();
	cin>>n>>k;
	e=n-k;
	f(i,0,e+1){
		p=C(i,e)*pow(e-i,n,mod)%mod;
		if(i%2){
			ans=(ans+mod-p)%mod;
		}
		else{
			ans=(ans+p)%mod;
		}
	}
	if(k>n-1) return cout<<0,0;
	if(k==0) cout<<fac[n];
	else{
		cout<<ans*2ll*C(k,n)%mod;
	}
}