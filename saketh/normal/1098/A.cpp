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

    vi par(N);
    vvi ch(N);
    for (int i = 1; i < N; i++) {
        cin >> par[i];
        ch[--par[i]].push_back(i);
    }

    vi sum(N);
    for (int i = 0; i < N; i++) {
        cin >> sum[i];
    }

    for (int i = 0; i < N; i++) {
        if (sum[i] == -1) {
            assert(i != 0);
            sum[i] = sum[par[i]];

            if (ch[i].size()) {
                int mc = INT_MAX;
                for (int c : ch[i]) {
                    mc = min(mc, sum[c]);
                }
                if (mc < sum[i]) {
                    cout << -1 << "\n";
                    return 0;
                }
                sum[i] = mc;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += sum[i] - (i ? sum[par[i]] : 0);
    }
    cout << ans << endl;

    return 0;
}