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

int get(ll N, int D, ll inx) {
    if (D <= 1) return N;

    ll left = (1ll << (D - 1)) - 1;

    if (inx < left) return get(N/2, D - 1, inx);
    if (inx == left) return N & 1;
    return get(N/2, D - 1, inx - left - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N, L, R;
    cin >> N >> L >> R;

    L--, R--;

    int D = 64 - __builtin_clzll(N);

    int ans = 0;
    for (ll i = L; i <= R; i++) {
        ans += get(N, D, i);
    }
    cout << ans << endl;

    return 0;
}