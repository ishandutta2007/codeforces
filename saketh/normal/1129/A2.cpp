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

    int N, M;
    cin >> N >> M;

    vvi targ(N);
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        targ[s-1].push_back(t-1);
    }

    vi add(N, INT_MAX);
    for (int i = 0; i < N; i++) {
        if (targ[i].size()) {
            for (int v : targ[i])
                add[i] = min(add[i], (v + N - i) % N);
        }
    }

    for (int s = 0; s < N; s++) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!targ[i].size()) continue;
            int req = N * (targ[i].size() - 1) + ((i + N - s) % N) + add[i];
            ans = max(ans, req);
        }

        if (s) cout << " ";
        cout << ans;
    }
    cout << endl;

    return 0;
}