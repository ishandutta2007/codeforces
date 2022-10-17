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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi g(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    bool ok = true;

    vi tag(N, INT_MAX);
    tag[0] = 0;
    int ct = 1, lt = 0;

    for (int _i = 0; _i < N; _i++) {
        int nxt;
        cin >> nxt;
        nxt--;

        if (tag[nxt] == INT_MAX || tag[nxt] < lt) {
            ok = false;
            break;
        }
        lt = max(lt, tag[nxt]);

        int nt = ct;
        for (int j : g[nxt]) {
            if (tag[j] == INT_MAX) {
                tag[j] = ct;
                nt++;
            }
        }
        ct = nt;
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}