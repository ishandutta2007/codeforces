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
typedef pair<ll,int> pli;

const int maxn=2e5 + 10,mod=1e9+7;
const ll inf=3e18;

pair<pll,ll> p[maxn];
set<pli> st1, st2, st3, other;
ll L[maxn], R[maxn], T[maxn];
ll pos;

void Add(int i){
    other.erase({L[i]+T[i],i});
    st1.insert({T[i],i});
    st2.insert({R[i],i});
    st3.insert({R[i]-T[i]+1, i});
}
void Erase(int i){
    st1.erase({T[i],i});
    st2.erase({R[i],i});
    st3.erase({R[i]-T[i]+1, i});
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i].F.F>>p[i].F.S>>p[i].S;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
	L[i]= p[i].F.F;
	R[i]= p[i].F.S;
	T[i]= p[i].S;
	other.insert({L[i]+T[i], i});
    }

    pos=0;
    int pt=0;
    ll ans=0;
    
    while(pt<n || sz(st1)){
	ll nxt=min( pt < n ? p[pt].F.F : inf, st2.empty() ? inf : st2.begin()->F );
	if(!st1.empty()){
	    ll num=(nxt - pos) / (st1.begin()->F);
	    pos+= (st1.begin()->F) * num;
	    ans+=num;	    
	}
	while(sz(st3) && pos>=(st3.begin()->F)){
	    Erase(st3.begin()->S);
	}
	if(pt==n && sz(st1)==0) break;
	ll A=sz(st1)==0 ? inf : pos + T[ st1.begin()->S ];
	ll B= pt==n     ? inf : other.begin()->F;
	if(A<B){
	    pos+= T[ st1.begin()->S ];
	    ans++;
	}
	else{
	    int id= other.begin()->S;
	    while(pt<=id){
		Add(pt);
		pt++;
	    }
	    pos=L[id];
	}
	while(sz(st3) && pos>=(st3.begin()->F)){
	    Erase(st3.begin()->S);
	}
	while(pt<n && L[pt]<=pos){
	    Add(pt);
	    pt++;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")