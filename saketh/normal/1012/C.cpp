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

    vi hill(N);
    for (int i = 0; i < N; i++) {
        cin >> hill[i];
    }

    int H = (N + 1) / 2;

    const int INF = INT_MAX / 2;
    vvi f(N + 1, vi(H + 1, INF)); // last hill has a house
    vvi g(N + 1, vi(H + 1, INF)); // last hill doesn't have a house
    vvi h(N + 1, vi(H + 1, INF)); // last hill guaranteed < successor

    g[0][0] = 0;
    h[0][0] = 0;

    auto sm = [](int &a, int b) { a = min(a, b); };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            if (j) sm(f[i+1][j], h[i][j-1]);
            if (i > 0 && i + 1 < N) {
                int lb = max(0, hill[i] - min(hill[i-1], hill[i+1]) + 1);
                sm(g[i+1][j], f[i][j] + lb);
                sm(g[i+1][j], g[i][j] + lb);
                sm(h[i+1][j], f[i][j] + lb);
                sm(h[i+1][j], g[i][j] + lb);
            }
            if (i > 0) {
                int l = max(0, hill[i] - hill[i-1] + 1);
                sm(g[i+1][j], f[i][j] + l);
                sm(g[i+1][j], g[i][j] + l);
            }
            if (i + 1 < N) {
                int l = max(0, hill[i] - hill[i+1] + 1);
                sm(g[i+1][j], g[i][j] + l);
                sm(h[i+1][j], g[i][j] + l);
            }
            sm(g[i+1][j], g[i][j]);
        }
    }

    for (int j = 1; j <= H; j++)
        cout << min(f[N][j], g[N][j]) << " ";
    cout << endl;

    return 0;
}