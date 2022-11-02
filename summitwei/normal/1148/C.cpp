#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
int p[MN];

vpii swaps;

void swp(int a, int b){
    if(abs(a-b) >= n/2){
        swaps.pb(mp(a, b));
        return;
    }
    if(a <= n/2 && b > n/2){
        int tmp = 1;
        swaps.pb(mp(b, tmp));
        swaps.pb(mp(tmp, n));
        swaps.pb(mp(a, n));
        swaps.pb(mp(n, tmp));
        swaps.pb(mp(tmp, b));
    } else if(a <= n/2 && b <= n/2){
        swaps.pb(mp(a, n));
        swaps.pb(mp(b, n));
        swaps.pb(mp(a, n));
    } else if(a > n/2 && b <= n/2){
        swaps.pb(mp(b, n));
        swaps.pb(mp(n, 1));
        swaps.pb(mp(a, 1));
        swaps.pb(mp(1, n));
        swaps.pb(mp(n, b));
    } else if(a > n/2 && b > n/2){
        swaps.pb(mp(a, 1));
        swaps.pb(mp(b, 1));
        swaps.pb(mp(a, 1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> p[i];

    FOR(i, 1, n){
        if(i == p[i]) continue;
        swp(i, p[i]);
        swap(p[i], p[p[i]]);
        i--;
    }

    cout << swaps.size() << "\n";
    F0R(i, swaps.size()){
        cout << swaps[i].f << " " << swaps[i].s << "\n";
    }

    return 0;
}