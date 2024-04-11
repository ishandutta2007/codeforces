#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 100;

int N, M;
bool res[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    if (N >= M) {
        cout << "YES\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        v %= M;

        res[i][v] = true;

        if (i > 0) {
            for (int r = 0; r < M; r++) {
                if(res[i-1][r]) res[i][r] = true;
                if(res[i-1][(r-v+M)%M]) res[i][r] = true;
            }
        }
    }

    cout << (res[N-1][0] ? "YES" : "NO") << "\n";
}