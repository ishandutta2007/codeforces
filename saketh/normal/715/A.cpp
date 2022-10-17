#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll find(ll arg) {
    ll hi = 1;

    while (hi * hi < arg)
        hi *= 2;

    ll lo = 1;
    ll ans = hi;

    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        if (mi * mi >= arg) {
            ans = mi;
            hi = mi - 1;
        }
        else {
            lo = mi + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    ll val = 2;

    for (ll lvl = 1; lvl <= N; lvl++) {
        // need to increase to a number whose square root is a multiple of (lvl+1)
        // or, a number who is x * x * (lvl + 1)^2


        ll fac = (lvl + 1) * (lvl + 1);
        ll now = val / fac;

        // want the smallest square exceeding "now"
        ll sqr = lvl;

        cout << (fac * sqr) - (val / lvl) << "\n";

        val = (lvl + 1) * sqr;
    }

    return 0;
}