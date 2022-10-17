#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1024;
const ll INF = 1e18;

int N, M;
ll rare[MAXN][MAXN];
ll row[MAXN], col[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> rare[i][j];

            row[i] += rare[i][j];
            col[j] += rare[i][j];
        }
    }
    
    ll xc = INF, bx = -1;

    for (int x = 0; x <= N; x++) {
        ll mc = 0;
        for (int r = 0; r < N; r++) {
            ll d = 4 * abs(x - r);
            if(r < x) d -= 2;
            else d += 2;

            mc += d * d * row[r];
        }

        if(mc < xc) {
            xc = mc;
            bx = x;
        }
    }

    ll yc = INF, by = -1;

    for (int y = 0; y <= M; y++) {
        ll mc = 0;
        for (int c = 0; c < M; c++) {
            ll d = 4 * abs(y - c);
            if(c < y) d -= 2;
            else d += 2;

            mc += d * d * col[c];
        }

        if(mc < yc) {
            yc = mc;
            by = y;
        }
    }

    cout << xc + yc << "\n";
    cout << bx << " " << by << "\n";
}