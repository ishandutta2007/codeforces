#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000000LL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n;
ll a[MN];
ll tot;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        tot += a[i];
    }
    if(tot == 1){
        cout << "-1\n";
        return 0;
    }
    ll mn = INF;
    ll res = tot;
    for(ll md = 2; md*md <= res; ++md){
        if(res % md != 0) continue;
        while(res % md == 0) res /= md;
        //cout << "checking " << md << "\n";
        ll cur = 0;
        ll sm = 0;
        F0R(i, n){
            cur += a[i];
            cur %= md;
            sm += min(cur, md-cur);
        }
        mn = min(mn, sm);
    }
    if(res != 1){
        ll cur = 0;
        ll sm = 0;
        F0R(i, n){
            cur += a[i];
            cur %= res;
            sm += min(cur, res-cur);
        }
        mn = min(mn, sm);
    }

    if(mn == INF) cout << "-1\n";
    else cout << mn << "\n";
    
    return 0;
}