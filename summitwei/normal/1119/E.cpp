#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
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
ll a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n) cin >> a[i];

    ll ans = 0;
    ll rem = 0;
    F0R(i, n){
        ll amt = min(a[i]/2, rem);
        rem -= amt;
        a[i] -= 2*amt;
        ans += amt;

        amt = a[i]/3;
        a[i] -= 3*amt;
        ans += amt;

        rem += a[i];
    }

    cout << ans << "\n";
    return 0;
}