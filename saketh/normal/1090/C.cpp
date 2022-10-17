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

    int totalSize = 0;
    vi sz(N);
    vi ord(N);
    vvi have(M);

    for (int i = 0; i < N; i++) {
        cin >> sz[i];
        totalSize += sz[i];
        for (int j = 0, v; j < sz[i]; j++) {
            cin >> v;
            have[v-1].push_back(i);
        }
        ord[i] = i;
    }

    sort(all(ord), [&sz](int i, int j) {
        return sz[i] < sz[j];
    });
    vi rank(N);
    for (int i = 0; i < N; i++)
        rank[ord[i]] = i;

    vi targ(N);
    set<int> smalls;
    for (int i = 0; i < N; i++) {
        targ[i] = (totalSize + rank[i]) / N;
        if (sz[i] < targ[i])
            smalls.insert(i);
    }

    vector<array<int, 3>> moves;
    for (int t = 0; t < M; t++) {
        vi tmp;
        for (int i : have[t]) {
            if (sz[i] < targ[i]) {
                smalls.erase(i);
                tmp.push_back(i);
            }
        }

        for (int i : have[t]) {
            if (sz[i] > targ[i] && smalls.size() > 0) {
                int to = *smalls.begin();
                smalls.erase(smalls.begin());
                moves.push_back({ i, to, t });
                sz[i]--;
                sz[to]++;
                if (sz[to] < targ[to])
                    tmp.push_back(to);
            }
        }

        smalls.insert(all(tmp));
    }

    cout << moves.size() << "\n";
    for (auto [f, t, k] : moves) {
        cout << f + 1 << " " << t + 1 << " " << k + 1 << "\n";
    }

    return 0;
}