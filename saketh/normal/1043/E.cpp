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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi x(N), y(N), ord(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        ord[i] = i;
    }

    sort(all(ord), [&](int i, int j) {
        return (x[i] - y[i]) < (x[j] - y[j]);
    });

    /*for (int i = 0; i < ord.size(); i++) {
        for (int j = i + 1; j < ord.size(); j++) {
            assert((x[ord[i]] + y[ord[j]] <= x[ord[j]] + y[ord[i]]));
        }
    }*/

    vll xs(N), ys(N);
    for (int i = 0; i < N; i++) {
        xs[i] = x[ord[i]];
        ys[i] = y[ord[i]];
        if (i) {
            xs[i] += xs[i-1];
            ys[i] += ys[i-1];
        }
    }

    auto get_sum = [](vll &vec, int i, int j) {
        if (i > j) return 0ll;
        if (i) return vec[j] - vec[i-1];
        return vec[j];
    };

    vll ans(N);
    for (int i = 0; i < N; i++) {
        ans[ord[i]] += y[ord[i]] * 1ll * i;
        ans[ord[i]] += get_sum(xs, 0, i-1);
        ans[ord[i]] += x[ord[i]] * 1ll * (N - 1 - i);
        ans[ord[i]] += get_sum(ys, i+1, N-1);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        ll res = min(x[u-1] + y[v-1], x[v-1] + y[u-1]);
        ans[u-1] -= res;
        ans[v-1] -= res;
    }

    for (ll v : ans)
        cout << v << " ";
    cout << endl;
    return 0;
}