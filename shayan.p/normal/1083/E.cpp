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
typedef long double ld;

const int maxn=1e6+10,mod=1e9+7;
const ll inf=4e18;

int n;
pair<pll,ll>p[maxn];
ll dp[maxn],ans;

struct CHT{
    vector<pll>vec;
    inline ll gety(int ind,ll x){
	return vec[ind].F*x+vec[ind].S;
    }
    bool bad(pll A,pll B,pll C){
	//	return (ld(B.S-A.S)/ld(B.F-A.F))>(ld(B.S-C.S)/ld(B.F-C.F));
	return ld(B.S-A.S)*ld(B.F-C.F)>=ld(B.S-C.S)*ld(B.F-A.F);
    }
    void add(ll a,ll b){
	if(sz(vec)>0 && vec.back().F==a){
	    if(b<vec.back().S) vec.pop_back();
	    else return;
	}
	while(sz(vec)>1 && bad(vec[sz(vec)-2],vec[sz(vec)-1],{a,b}))
	    vec.pop_back();
	vec.PB({a,b});
    }
    ll ask(ll x){
	if(sz(vec)==0) return inf;
	int l=0,r=sz(vec)-1;
	ll ans=gety(0,x);;
	while(l<r){
	    int mid=(l+r)>>1;
	    if(gety(mid,x)>gety(mid+1,x))
		l=mid+1,ans=gety(mid+1,x);
	    else
		r=mid,ans=gety(mid,x);
	}
	return ans;
    }
};CHT cht;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
	cin>>p[i].F.F>>p[i].F.S>>p[i].S;
    sort(p,p+n);
    for(int i=n-1;i>=0;i--){
	dp[i]=p[i].F.F*p[i].F.S-p[i].S+max(ll(0),-cht.ask(-p[i].F.F));
	ans=max(ans,dp[i]);
	cht.add(-p[i].F.S,-dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}