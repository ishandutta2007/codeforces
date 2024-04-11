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
 
const int N=2002,mod=998244353;

int n,p1,p2,ans,b1[N],b2[N],a[N];
string s;

//math
ll fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){if(k>n) return 0; return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int solve(int x,int y){
	ll res=1;
	if(b1[x]>y || b2[n-1]-b2[x]>y) return 0;
	p1=y-b1[x],p2=y-(b2[n-1]-b2[x]);
	res=C(p1,a[x])*C(p2,a[n-1]-a[x])%mod;
	return res;
}

int main(){
	make_fac();
	cin>>s;
	n=s.size();
	b1[0]=(s[0]=='(');
	b2[0]=(s[0]==')');
	a[0]=(s[0]=='?');
	f(i,1,n){
		b1[i]=b1[i-1]+(s[i]=='(');
		b2[i]=b2[i-1]+(s[i]==')');
		a[i]=i+1-b1[i]-b2[i];
	}
	
	f(i,0,n-1)
		f(j,1,n/2+1)
			ans=(ans+(solve(i,j)*j%mod))%mod;
	cout<<ans;
}