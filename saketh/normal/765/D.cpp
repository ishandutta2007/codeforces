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

    vi f(N + 1);
    vb self(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> f[i];
        if (f[i] == i) self[i] = true;
    }

    vi g(N + 1);
    int M = 0;

    for (int i = 1; i <= N; i++) {
        if (self[i]) {
            g[i] = ++M;
            continue;
        }
        if (self[f[i]]) continue;

        cout << -1 << endl;
        return 0;
    }

    vi h(M + 1);

    for (int i = 1; i <= N; i++) {
        if (self[i]) h[g[i]] = i;
        else g[i] = g[f[i]];
    }

    cout << M << endl;
    for (int i = 1; i <= N; i++)
        cout << g[i] << " ";
    cout << endl;
    for (int i = 1; i <= M; i++)
        cout << h[i] << " ";
    cout << endl;

    return 0;
}