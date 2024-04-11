#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1234;
const int INF = 1e9;

int n, m, x, y, kol, cur;
char a[N][N];
int c0[N], c1[N];
int p0[N], p1[N];

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d %d %d %d ", &n, &m, &x, &y);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%c ", &a[i][j]);

    for (int i = 0; i < m; i++) {
        kol = 0;
        for (int j = 0; j < n; j++)
            kol += (a[j][i] == '#' ? 1 : 0);
        c0[i] = kol;
        c1[i] = n - kol;
    }

    p0[0] = p1[0] = 0;

    for (int i = 1; i <= m; i++) {
        

        p0[i] = INF;
        cur = 0;
        if (i >= x) {
            for (int j = 0; j < x; j++) 
                cur += c0[i - j - 1];
            for (int j = x; j <= y; j++) {
                p0[i] = min(p0[i], cur + p1[i - j]);
                if (i - j == 0) break;
                cur += c0[i - j - 1];
            }
        }

        p1[i] = INF;
        cur = 0;
        if (i >= x) {
            for (int j = 0; j < x; j++) 
                cur += c1[i - j - 1];
            for (int j = x; j <= y; j++) {
                p1[i] = min(p1[i], cur + p0[i - j]);
                if (i - j == 0) break;
                cur += c1[i - j - 1];
            }
        }
    }

    cout << min(p0[m], p1[m]);

    //while(true);
}