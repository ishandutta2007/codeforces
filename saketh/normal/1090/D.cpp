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

    vector<array<int, 2>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1];
        if (edges[i][0] > edges[i][1])
            swap(edges[i][0], edges[i][1]);
    }

    sort(all(edges));
    edges.erase(unique(all(edges)), edges.end());

    int t = 0, a = -1, b = -1;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (t < edges.size() && edges[t][0] == i && edges[t][1] == j) {
                t++;
            }
            else {
                a = i;
                b = j;
                goto DONE;
            }
        }
    }

    DONE:
    if (a == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    t = 3;
    for (int i = 1; i <= N; i++) {
        if (i == a) cout << 1 << " ";
        else if (i == b) cout << 2 << " ";
        else cout << t++ << " ";
    }
    cout << "\n";

    t = 3;
    for (int i = 1; i <= N; i++) {
        if (i == a) cout << 1 << " ";
        else if (i == b) cout << 1 << " ";
        else cout << t++ << " ";
    }
    cout << "\n";

    return 0;
}