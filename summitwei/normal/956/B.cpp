#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n; ll u;
ll e[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> u;
    FOR(i, 1, n){
        cin >> e[i];
    }
    long double ans = -1;
    FOR(i, 1, n){
        ll o = e[i]+u;
        int res = upper_bound(e+1, e+n+1, o)-e-1;
        if(res <= i+1) continue;
        ans = max(ans, ((long double)e[res]-e[i+1]) / (e[res]-e[i]));
    }

    if(ans < 0){
        cout << "-1\n";
    } else{
        cout << fixed << setprecision(10) << ans << "\n";
    }

    return 0;
}