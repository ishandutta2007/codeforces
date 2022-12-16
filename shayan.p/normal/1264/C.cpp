// Remember...

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

const int maxn=2e5+10,mod=998244353;
const ll inf=1e18;

int n;
pii p[4 * maxn];
int zr[4 * maxn];
int a[maxn];

int Pow(int a,int b){
    int ans=1;
    for(; b; b>>=1, a=1ll*a*a %mod)
	if(b&1)
	    ans=1ll*ans*a %mod;
    return ans;
}

pii operator + (pii a, int num){
    a.S= (a.S + num) %mod;
    return a;
}
pii operator * (int num, pii a){
    a.F = 1ll*a.F * num %mod;
    a.S = 1ll*a.S * num %mod;
    return a;
}

void build(int l=0, int r=n, int id=1){
    if(r-l==1){
	zr[id]= a[l];
	p[id]= {a[l], 1};
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    zr[id] = 1ll*zr[2*id] * zr[2*id+1] %mod;
    p[id] = (p[2*id].F * p[2*id+1]) + p[2*id].S;
}

pii ask1(int f,int s,int l=0,int r=n,int id=1){
    if(f>=s || l>=r || s<=l || r<=f) return {1,0};
    if(f<=l && r<=s) return p[id];
    int mid=(l+r)>>1;
    pii a=ask1(f,s,l,mid,2*id), b=ask1(f,s,mid,r,2*id+1);
    return (a.F*b) + a.S;
}
int ask2(int f,int s,int l=0,int r=n,int id=1){
    if(f>=s || l>=r || s<=l || r<=f) return 1;
    if(f<=l && r<=s) return zr[id];
    int mid=(l+r)>>1;
    return 1ll* ask2(f,s,l,mid,2*id) * ask2(f,s,mid,r,2*id+1) %mod;
}

set<int> st;
int ans;

void calc(int l, int r, int x){
    ans = (1ll*ans + 1ll *x * ask1(l, r).S * Pow(ask2(l, r), mod-2) ) %mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>n>>q;
    for(int i=0; i<n; i++){
	cin>>a[i];
	a[i] = 1ll*a[i] * Pow(100, mod-2) %mod;
    }
    build();
    st.insert(0), st.insert(n);
    
    calc(0,n,1);

    while(q--){
	int x; cin>>x; --x;
	if(st.count(x)){
	    auto it = st.find(x);
	    calc( *prev(it), *it, -1);
	    calc( *it, *next(it), -1);
	    --it;
	    st.erase(next(it));
	    calc( *it, *next(it), 1);
	}
	else{
	    auto it= --st.lower_bound(x);
	    calc( *it, *next(it), -1);
	    st.insert(x);
	    calc( *it, *next(it), 1);
	    ++it;
	    calc( *it, *next(it), 1);		
	}
	cout<<(ans + mod) %mod<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")