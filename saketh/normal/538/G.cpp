#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 100;

void fail() {
    cout << "NO\n";
    exit(0);
}

ll floor(ll x, ll y) {
    return (x >= 0) ? (x / y) : ((x - y + 1) / y);
}

ll ceil(ll x, ll y) {
    return (x >= 0) ? ((x + y - 1) / y) : (x / y);
}

ll t[MAXN];

vector<bool> solve(int _N, int L, ll v[]) {
    int N = _N + 1;
    vector<ll> res(N), cyc(N), order(N);

    for (int i = 0; i < _N; i++) {
        if ((v[i] + t[i])&1) fail();
        v[i] = (v[i] + t[i]) / 2;

        res[i] = t[i] % L;
        cyc[i] = t[i] / L;
        order[i] = i;
    }

    v[N - 1] = 0;
    res[N - 1] = L;
    cyc[N - 1] = -1;
    order[N - 1] = N - 1;

    sort(order.begin(), order.end(), [&res](int i, int j) {
        return res[i] < res[j];
    });

    ll lo = 0, hi = L;
    for (int _i = 0; _i + 1 < N; _i++) {
        int i = order[_i], j = order[_i + 1];

        ll dk = cyc[j] - cyc[i], dx = v[j] - v[i], cap = res[j] - res[i];

        if (dk == 0) {
            if (dx < 0 || dx > cap) fail();
        } else if (dk > 0) {
            lo = max(lo, ceil(dx - cap, dk));
            hi = min(hi, floor(dx, dk));
        } else {
            lo = max(lo, ceil(-dx, -dk));
            hi = min(hi, floor(-dx + cap, -dk));
        }
    }

    if (lo > hi) fail();

    int sum = 0;
    vector<bool> ans;

    for (int _i = 0; _i < N; _i++) {
        int i = order[_i];

        while (lo * cyc[i] + sum < v[i]) {
            ans.push_back(1);
            sum++;
        }

        while (ans.size() < res[i])
            ans.push_back(0);
    }

    return ans;
}

int N, L;
ll x[MAXN], y[MAXN];
ll a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> L;
    N++;

    for (int i = 1; i < N; i++) {
        cin >> t[i] >> x[i] >> y[i];
        a[i] = x[i] + y[i];
        b[i] = x[i] - y[i];
    }

    vector<bool> s1 = solve(N, L, a), s2 = solve(N, L, b);

    for (int i = 0; i < L; i++) {
        cout << "LDUR"[2 * s1[i] + s2[i]];
    }
    cout << "\n";
}