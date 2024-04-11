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
#define INF 40000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
ll xo, yo, ax, ay, bx, by;
ll xs, ys, t;
vector<pll> stuff;
vll sm;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> xo >> yo >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
 
    stuff.pb({xo, yo});
    ll cx = xo, cy = yo;
    sm.pb({xo+yo});
    while(cx <= INF && cy <= INF){
        cx = cx*ax+bx;
        cy = cy*ay+by;
        stuff.pb({cx, cy});
        //cout << cx << " " << cy << "\n";
        sm.pb(cx+cy);
    }
    int ans = 0;
    F0R(i, stuff.size()){
        //cout << "doing " << i << "\n";
        ll dsf = abs(stuff[i].f-xs)+abs(stuff[i].s-ys);
        //cout << dsf << "\n";
        if(dsf > t) continue;
        ll mov = t-dsf+sm[i];
        int loc = upper_bound(sm.begin(), sm.end(), mov)-sm.begin();
        ll mov2 = sm[i]-(t-dsf);
        int loc2 = lower_bound(sm.begin(), sm.end(), mov2)-sm.begin();
        ans = max(ans, max(i-loc2+1, loc-i));
        //cout << sm[i] << " " << t << " " << dsf << "\n";
        //cout << i << " " << mov << " " << mov2 << "\n";
    }
    cout << ans << "\n";
 
    return 0;
}