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

const int maxn = 2510, mod = 1e9 + 7;
const ll inf = 1e18;

istream& operator >> (istream &in, pii &p){
    in >> p.F >> p.S;
    return in;
}
pii operator - (pii a, pii b){
    return {a.F - b.F, a.S - b.S};
}
ll operator * (pii a, pii b){
    return 1ll * a.F * b.S - 1ll * a.S * b.F;
}

pii p[maxn];
vector<pii> ev;
int arr[maxn], pos[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin >> n;
    for(int i = 0; i < n; i++)
	cin >> p[i], arr[i] = pos[i] = i;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	    if(i!=j)
		ev.PB({i,j});
    sort(p, p+n, [](pii a, pii b){ return a.S == b.S ? a.F < b.F : a.S < b.S; } );
    
    sort( ev.begin(), ev.end(), [](pii a, pii b){
	    pii A = p[a.F] - p[a.S], B = p[b.F] - p[b.S];
	    bool _A = A.S < 0 || (A.S == 0 && A.F < 0);
	    bool _B = B.S < 0 || (B.S == 0 && B.F < 0);
	    return _A != _B ? _A < _B : (A * B > 0);
	});    
    ll ans = ( 1ll * n * (n-1) * (n-2) * (n-3) * (n-4) ) / 24;
    for(pii p : ev){
	int A = p.F, B = p.S;
	swap( pos[A], pos[B] );
	swap( arr[ pos[A] ], arr[ pos[B] ] );
	int num = n - max(pos[A], pos[B]) -1;
	ans-= (1ll * num * (num-1) * (num-2)) / 6;
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")