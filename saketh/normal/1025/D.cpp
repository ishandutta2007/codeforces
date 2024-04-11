#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    vvb g(N, vb(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (gcd(vals[i], vals[j]) > 1)
                g[i][j] = true;

    vvb dp(N + 1, vb(2 * N, false));
    dp[0] = vb(2 * N, true);

    for (int l = 1; l <= N; l++) {
        for (int i = 0; i + l <= N; i++) {
            for (int r = i; r < i+l; r++) {
                // can we root this subtree at r?
                bool ok = dp[r - i][2 * i + 1];
                int rl = (i + l - 1) - r;
                if (rl > 0)
                    ok &= dp[rl][2 * (r+1)];

                // case 1: subtree root's parent is i-1
                if (i == 0 || g[r][i-1]) {
                    if (ok) dp[l][2 * i] = true;
                }
                // case 2: subtree root's parent is i+l
                if ((i+l) == N || g[r][i+l]) {
                    if (ok) dp[l][2 * i + 1] = true;
                }
            }
        }
    }

    for (int r = 0; r < N; r++) {
        if (dp[N][2 * r]) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}