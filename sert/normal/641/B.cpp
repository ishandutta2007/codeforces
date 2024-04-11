#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 500 + 34;

struct pt {
    int x, y;
    pt(){}
    pt(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

pt a[N][N], h;
int ans[N][N];
int rs[N], cs[N];
int n, m, q, r, t, c, x, rr, cc;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        a[i][j] = pt(j, i);
    }
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            x--;
            h = a[x][0];
            for (int i = 0; i < m - 1; i++)
                a[x][i] = a[x][i + 1];
            a[x][m - 1] = h;
        }
        if (t == 2) {
            cin >> x;
            x--;
            h = a[0][x];
            for (int i = 0; i < n - 1; i++)
                a[i][x] = a[i + 1][x];
            a[n - 1][x] = h;
        }
        if (t == 3) {
            cin >> r >> c >> x;
            r--;
            c--;
            ans[a[r][c].y][a[r][c].x] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}