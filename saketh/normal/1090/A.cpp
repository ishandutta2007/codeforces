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
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> comp(N);
    for (int i = 0; i < N; i++) {
        cin >> comp[i].second;
        for (int j = 0; j < comp[i].second; j++) {
            int v;
            cin >> v;
            comp[i].first = max(comp[i].first, v);
        }
    }

    sort(all(comp));

    ll ans = 0;
    for (int i = 0; i < comp.size(); i++) {
        ans += comp[i].second * 1ll * (comp.back().first - comp[i].first);
    }
    cout << ans << endl;

    return 0;
}