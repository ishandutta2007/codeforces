// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll pa[maxn],pb[maxn],f[maxn];
ll n,m;

struct Segment{
    vector<ll>v[4*maxn];
    void Merge(vector<ll>&vec,vector<ll>&a,vector<ll>&b){
	ll pa=0,pb=0;
	while((pa+pb)<(sz(a)+sz(b))){
	    if(pa==sz(a))
		vec.PB(b[pb++]);
	    else if(pb==sz(b))
		vec.PB(a[pa++]);
	    else if(a[pa]<b[pb])
		vec.PB(a[pa++]);
	    else
		vec.PB(b[pb++]);
	}
    }
    void build(ll l,ll r,ll *p,ll id=1){
	if(l==r){
	    v[id].PB(p[r]);
	    return;
	}
	ll mid=(l+r)/2;
	build(l,mid,p,2*id);
	build(mid+1,r,p,2*id+1);
	Merge(v[id],v[2*id],v[2*id+1]);
    }
    ll ask_vec(vector<ll>&vec,ll x){
	ll l=0,r=sz(vec)-1,ans=-1;
	while(l<=r){
	    ll mid=(l+r)/2;
	    if(vec[mid]<x){
		ans=mid;
		l=mid+1;
	    }
	    else{
		r=mid-1;
	    }
	}
	return ans+1;
    }
    ll ask(ll f,ll s,ll x,ll l,ll r,ll id=1){
	if(l>r || f>s || s<l || r<f )return 0;
	if(f<= l && r<= s) return ask_vec(v[id],x);
	ll mid=(l+r)/2;
	return ask(f,s,x,l,mid,2*id)+ask(f,s,x,mid+1,r,2*id+1);
    }
};Segment seg[2];

int main(){
    ll n,m;cin>>n>>m;
    FOR(i,1,n){
	ll x;cin>>x;
	pa[x]=i;
    }
    FOR(i,1,m){
	ll x;cin>>x;
	pb[x]=i;
    }
    seg[0].build(1,n,pa);
    seg[1].build(1,m,pb);
    ll k=0;
    FOR(i,1,n){
	while(k>0 && seg[0].ask(1,k,pa[k+1],1,n)!=seg[0].ask(i-k,i-1,pa[i],1,n) )
	    k=f[k];
	if(k==0 && i==1)
	    k=-1;
	f[i]=(++k);
    }
    k=0;
    ll ans=0;
    FOR(i,1,m){
	while(k>0 && seg[0].ask(1,k,pa[k+1],1,n)!=seg[1].ask(i-k,i-1,pb[i],1,m) )
	    k=f[k];
	if((++k)==n){
	    k=f[k];
	    ans++;
	}
    }
    cout<<ans;
}