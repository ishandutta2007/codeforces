#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

// returns { white, black }
array<ll, 2> ct(ll x1, ll y1, ll x2, ll y2) {
    if (x1 > x2 || y1 > y2) return { 0ll, 0ll };

    ll area = (abs(x1 - x2)+1ll) * (abs(y1 - y2) + 1ll);
    array<ll, 2> res = { area / 2, area / 2 };
    if (area&1) {
        res[(x1 + y1)&1]++;
    }
    return res;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    auto orig = ct(1, 1, M, N);
    auto white = ct(x1, y1, x2, y2);
    auto black = ct(x3, y3, x4, y4);
    auto both = ct(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));

    cout << orig[0] + white[1] - black[0] - both[1] << " ";
    cout << orig[1] - white[1] + black[0] + both[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}