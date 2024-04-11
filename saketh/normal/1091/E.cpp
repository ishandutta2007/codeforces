#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi solve(int N, const auto& bounds, bool par) {
    auto sanit = [&](ll i) {
        if (i < 0) return -1;
        if (i > N) return N + 1;
        return int(i);
    };
    vector<vector<array<int, 3>>> coll(N + 2);
    for (const auto& [x, y, l, r] : bounds) {
        coll[max(sanit(x), 0)].push_back({ sanit(y), sanit(l), sanit(r) });
    }

    priority_queue<pair<int, int>> lb, ub;
    lb.push({ 0, N + 1 });
    ub.push({ -N, N + 1 });

    vi res;
    for (int i = 0; i <= N; i++) {
        for (auto &[exp, l, u] : coll[i]) {
            lb.push({ l,  exp });
            ub.push({ -u, exp });
        }
        while (lb.top().second < i) lb.pop();
        while (ub.top().second < i) ub.pop();
        if ((i&1) == par && i >= lb.top().first && i <= -ub.top().first)
            res.push_back(i);
    }

    TRACE(vi res2;
    for (int i = par; i <= N; i += 2) {
        bool ok = true;
        for (auto [x, y, l, r] : bounds) {
            if (x <= i && i <= y)
                ok &= l <= i && i <= r;
        }
        if (ok) res2.push_back(i);
    }
    assert(res == res2);)

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi deg(N);
    for (int i = 0; i < N; i++) {
        cin >> deg[i];
    }
    sort(all(deg), greater<int>());

    bool par = false;
    for (int v : deg) {
        if (v&1) par = !par;
    }

    vll pref(N + 1);
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i-1] + deg[i-1];

    // sum over [i, N) of min(deg[i], l)
    auto min_sum = [&](int i, int l) {
        if (i >= N) return 0ll;
        auto it = upper_bound(deg.begin() + i, deg.end(), l, greater<int>());
        int inx = it - deg.begin();
        ll res = (inx - i) * 1ll * l;
        if (inx < N) res += pref[N] - pref[inx];

        TRACE(ll slow = 0;
        for (int j = i; j < N; j++)
            slow += min(deg[j], l);
        assert(slow == res);)

        return res;
    };

    vector<array<ll, 4>> bounds;
    for (int k = 0; k <= N; k++) {
        WATCH(k);
        // if rank <= k
        bounds.push_back({ k < N ? deg[k] : LLONG_MIN, LLONG_MAX, LLONG_MIN, k * 1ll * (k + 1) + min_sum(k, k + 1) - pref[k] });
        WATCHC(bounds.back());

        if (k < N) {
            ll diff = pref[k + 1] - k * 1ll * (k + 1) - min_sum(k + 1, k + 1);
            // if rank > k and val >= k
            bool ok = diff <= k + 1;
            bounds.push_back({ k + 1, deg[k] - 1, ok ? LLONG_MIN : LLONG_MAX, ok ? LLONG_MAX : LLONG_MIN });
        WATCHC(bounds.back());

            // if rank > k and val < k
            bounds.push_back({ LLONG_MIN, min(deg[k] - 1, k), diff, LLONG_MAX });
        WATCHC(bounds.back());
        }
    }

    auto res = solve(N, bounds, par);
    if (!res.size()) cout << -1 << endl;
    else {
        for (int v : res) cout << v << " ";
        cout << endl;
    }

    return 0;
}