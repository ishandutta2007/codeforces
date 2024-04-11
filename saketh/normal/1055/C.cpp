#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

ll solve(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
    ll g = __gcd(ta, tb);
    ll r = la % g;

    ll match = lb - (lb % g) + r;
    if (match < lb) match += g;

    return min((ra - la + 1), max(0ll, (rb - match + 1)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll la, ra, ta;
    cin >> la >> ra >> ta;
    ll lb, rb, tb;
    cin >> lb >> rb >> tb;

    ll ans = 0;
    ans = max(ans, solve(la, ra, ta, lb, rb, tb));
    ans = max(ans, solve(lb, rb, tb, la, ra, ta));
    cout << ans << endl;

    return 0;
}