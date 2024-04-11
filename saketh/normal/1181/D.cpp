#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    vi hosted(M);
    for (int i = 0, h; i < N; i++) {
        cin >> h;
        hosted[h - 1]++;
    }

    vi order(M);
    for (int i = 0; i < M; i++) order[i] = i;
    sort(all(order), [&](int i, int j) {
        if (hosted[i] != hosted[j]) return hosted[i] < hosted[j];
        return i < j;
    });

    vector<pair<ll, int>> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q].first;
        queries[q].second = q;
    }
    sort(all(queries));

    vi ans(Q);
    int did = 0;

    ll year = N;
    ordered_set active;

    for (int _i = 0; _i < M; _i++) {
        active.insert(order[_i]);

        ll until = _i + 1 < M
          ? year + ll(active.size()) * (hosted[order[_i+1]] - hosted[order[_i]])
          : LLONG_MAX;

        for (; did < Q && queries[did].first <= until; did++) {
            ans[queries[did].second] = 1 + *active.find_by_order(
                    (queries[did].first - year - 1) % active.size());
        }

        year = until;
    }

    for (int v : ans)
        cout << v << "\n";

    return 0;
}