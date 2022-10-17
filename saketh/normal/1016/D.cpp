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

    int N, M;
    cin >> N >> M;
    vi rows(N), cols(M);
    for (int i = 0; i < N; i++)
        cin >> rows[i];
    for (int i = 0; i < M; i++)
        cin >> cols[i];

    vvi out(N, vi(M));
    for (int b = 0; b <= 30; b++) {
        bool rs = false;
        for (int v : rows) rs ^= (v >> b)&1;
        bool cs = false;
        for (int v : cols) cs ^= (v >> b)&1;
        if (rs != cs) {
            cout << "NO\n";
            return 0;
        }

        out[0][0] |= ((rs ^ (rows[0] >> b) ^ (cols[0] >> b))&1) << b;
        for (int i = 1; i < N; i++)
            out[i][0] |= ((rows[i] >> b)&1) << b;
        for (int i = 1; i < M; i++)
            out[0][i] |= ((cols[i] >> b)&1) << b;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << out[i][j] << " ";
        cout << "\n";
    }

    return 0;
}