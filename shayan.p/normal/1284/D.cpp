// They can't break me, as long as I know who I am...

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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

pair<pii, pii> p[maxn];
int n;

bool check(){
    multiset<int> L, R;
    sort(p,p+n);
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    for(int i = 0; i < n; i++){
	while(sz(pq) && p[i].F.F > pq.top().F){
	    int id = pq.top().S;
	    pq.pop();
	    L.erase( L.find( p[id].S.F ) );
	    R.erase( R.find( p[id].S.S ) );
	}
	if(sz(pq)){
	    if( (*R.begin()) < p[i].S.F || (*L.rbegin()) > p[i].S.S )
		return 1;	    
	}
	pq.push({p[i].F.S, i});
	L.insert( p[i].S.F );
	R.insert( p[i].S.S );
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n;
    for(int i = 0; i < n; i++)
	cin>>p[i].F.F >>p[i].F.S>>p[i].S.F>>p[i].S.S;
    if(check())
	return cout<<"NO\n",0;
    for(int i = 0; i < n; i++)
	swap(p[i].F, p[i].S);
    if(check())
	return cout<<"NO\n",0;
    return cout<<"YES\n",0;    
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")