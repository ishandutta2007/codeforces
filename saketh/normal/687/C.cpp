#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 505;

    vector<vector<int>> pos(MAXV, vector<int>(MAXV, false));
    pos[0][0] = true;

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int V;
        cin >> V;

        for (int m = MAXV - 1; m >= 0; m--) {
            for (int a = 0; a <= m; a++) {
                if (m < V) continue;

                pos[m][a] |= pos[m-V][a];
                if (V <= a)
                    pos[m][a] |= pos[m-V][a-V];
            }
        }
    }

    vector<int> res;
    for (int v = 0; v <= K; v++)
        if (pos[K][v])
            res.push_back(v);

    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}