#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll divs(ll A) {
    vll res;
    for (ll i = 1; i * i <= A; i++) {
        if (A % i != 0) continue;
        res.push_back(i);
        if (A/i != i) res.push_back(A/i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, K;
    cin >> N >> M >> K;

    ll prod = 2ll * N * M;
    if (prod % K != 0) {
        cout << "NO\n";
        return 0;
    }
    prod /= K;

    cout << "YES\n";
    cout << "0 0\n";
    for (ll _x : divs(N)) {
        for (ll x : { _x, 2 * _x }) {
            if (prod % x != 0) continue;
            ll y = prod/x;
            if (x <= N && y <= M) {
                cout << x << " 0\n";
                cout << "0 " << y << "\n";
                return 0;
            }
        }
    }

    assert(false);
}