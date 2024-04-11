#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vvi perm(M, vi(N));
    vvi vloc(M, vi(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> perm[i][j];
            vloc[i][--perm[i][j]] = j;
        }
    }

    ll ans = 0;
    int len = 1;
    vi begin(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            begin[j] = vloc[j][perm[0][i]];
        len = max(1, len - 1);

        while (true) {
            bool ok = true;
            for (int j = 0; j < M; j++) {
                if (begin[j] + len >= N) {
                    ok = false;
                    break;
                }
                if (perm[j][begin[j]+len] != perm[0][begin[0]+len]) {
                    ok = false;
                    break;
                }
            }
            if (ok) len++;
            else break;
        }

        ans += len;
    }

    cout << ans << endl;
    return 0;
}