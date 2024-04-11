// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e7+10,mod=1e9+7;
const ll inf=1e18;

map<ll,pll>mp;

ll solve(ll a,ll b,ll l,ll r){
    l-=b;r-=b;
    if(l<0){
	ll delta=((-l)/a)*a+a;
	l+=delta,r+=delta;
    }
    r-=r%a;
    return (r-l+a)/a;
}
ll Mul(ll a,ll b,ll md){
    ll ans=0;
    while(b){
	if(b&1) ans=(ans+a)%md;
	a=(a+a)%md;
	b>>=1;
    }
    return ans;
}
ll Pow(ll a,ll b,ll md=inf){
    ll ans=1;
    while(b){
	if(b&1) ans=Mul(ans,a,md);
	a=Mul(a,a,md);
	b>>=1;
    }
    return ans;
}

void addp(ll p,ll num,ll b){
    if(mp.count(p)){
	pll A=mp[p],B={num,b};
	if(A.F<B.F) swap(A,B);
	ll pwb=Pow(p,B.F);
	if(B.S%pwb!=A.S%pwb) cout<<0<<endl,exit(0);
	mp[p]=A;
    }
    else{
	mp[p]={num,b};
    }
}
void f(ll a,ll b){
    for(ll p=2;p*p<=a;p++){
	int num=0;
	while(a%p==0) num++,a/=p;
	if(num>0)  addp(p,num,b);
    }
    if(a>1) addp(a,1,b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll a1,b1,a2,b2,l,r;cin>>a1>>b1>>a2>>b2>>l>>r;
    l=max(b1,max(b2,l));
    b1%=a1;b2%=a2;
    if(b1<0) b1+=a1;
    if(b2<0) b2+=a2;
    if(l>r) return cout<<0<<endl,0;
    f(a1,b1);f(a2,b2);
    if(mp.empty()) return cout<<(r-l+1)<<endl,0;
    ll ans=0,md=1;
    for(auto x:mp){
	md*=Pow(x.F,x.S.F);
    }
    for(auto x:mp){
	ll m=Pow(x.F,x.S.F),phi=(m/x.F)*(x.F-1);
	ans=(ans+Mul(Pow(md/m,phi,md),x.S.S,md))%md;
    }
    return cout<<solve(md,ans,l,r)<<endl,0;
}