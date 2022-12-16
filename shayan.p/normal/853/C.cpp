// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O1")
#pragma GCC Optimize("O2")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O4")
#pragma GCC Optimize("O5")

inline ll Cn2(ll x){
    return (x*(x-1))/2;
}

ll a[maxn],n;
vector<ll>val[4*maxn];

void Merge(vector<ll>&vec,vector<ll>&a,vector<ll>&b){
    ll pa=0,pb=0;
    while(ll(pa+pb)<ll(sz(a)+sz(b))){
	if(pa==ll(sz(a)))
	    vec.PB(b[pb++]);
	else if(pb==ll(sz(b)))
	    vec.PB(a[pa++]);
	else if(a[pa]<b[pb])
	    vec.PB(a[pa++]);
	else
	    vec.PB(b[pb++]);
    }
}

void build(ll l,ll r,ll id=1){
    if(l==r){
	val[id].PB(a[r]);
	return;
    }
    ll mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    Merge(val[id],val[2*id],val[2*id+1]);
}

ll ask_vec(vector<ll>&vec,ll x,bool t){
    if(sz(vec)==0)return 0;
    ll l=0,r=sz(vec)-1,id,ans=0;
    if(t){//greater equall
	id=sz(vec);
	while(l<=r){
	    ll mid=(l+r)/2;
	    if(vec[mid]>=x){
		id=mid;
		r=mid-1;
	    }
	    else{
		l=mid+1;
	    }
	}
	ans=sz(vec)-id;
    }
    else{// less equall
	id=-1;
	while(l<=r){
	    ll mid=(l+r)/2;
	    if(vec[mid]<=x){
		id=mid;
		l=mid+1;
	    }
	    else{
		r=mid-1;
	    }
	}
	ans=id+1;
    }
    return ans;
}

ll ask(ll f,ll s,ll x,bool t,ll l=1,ll r=n,ll id=1){
    if(f>s||l>r||s<l||r<f)return 0;
    if(f<=l&&r<=s) return ask_vec(val[id],x,t);
    ll mid=(l+r)/2;
    return ask(f,s,x,t,l,mid,2*id)+ask(f,s,x,t,mid+1,r,2*id+1);
}

int main(){
    ll q;scanf("%lld%lld",&n,&q);
    FOR(i,1,n)
	scanf("%lld",&a[i]);
    build(1,n);

    while(q--){
	ll l,d,r,u;scanf("%lld%lld%lld%lld",&l,&d,&r,&u);
	ll ans=Cn2(l-1)+Cn2(n-r)+Cn2(d-1)+Cn2(n-u)-Cn2(ask(1,l-1,d-1,0))-Cn2(ask(1,l-1,u+1,1))-Cn2(ask(r+1,n,d-1,0))-Cn2(ask(r+1,n,u+1,1));
	printf("%lld\n",(Cn2(n)-ans));
    }
}