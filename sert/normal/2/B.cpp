#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef int ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 1003;

ll n, a[M][M], x0 = -1;
ll b[2][M][M], p[2][M][M];

ll fv(ll x, ll a) {
    if (x == 0)
        return 0;
    ll an = 0;
    while (x % a == 0) {
        x /= a;
        an++;
    }
    return an;
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                b[0][i][j] = b[1][i][j] = 1000000000;
            else {
                scanf("%d", &a[i][j]);
                if (a[i][j] == 0) {
                    x0 = j;
                }
            }

    for (int iq = 0; iq < 2; iq++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (b[iq][i - 1][j] < b[iq][i][j - 1]) {
                    p[iq][i][j] = 'D';
                    b[iq][i][j] = b[iq][i - 1][j];
                } else {
                    p[iq][i][j] = 'R';
                    b[iq][i][j] = b[iq][i][j - 1];
                }
                if (i * j == 1) b[iq][i][j] = 0;
                b[iq][i][j] += fv(a[i][j], 2 + iq * 3);
            }
    }

    int t = 0;
    if (b[1][n][n] < b[0][n][n]) t = 1;

    if (b[t][n][n] >= 1 && x0 != -1) {
        cout << 1 << "\n";
        for (int i = 1; i < x0; i++) cout << 'R';
        for (int i = 1; i < n; i++) cout << 'D';
        for (int i = x0; i < n; i++) cout << 'R';
        return 0;
    }

    int x, y;
    x = y = n;
    string s;
    while (x != 1 || y != 1) {
        //cerr << x << " " << y << "\n";
        if (min(x, y) < 1) {cout << "fail"; return 34;}
        s += p[t][y][x];
        if (p[t][y][x] == 'D')
            y--;
        else
            x--;
    }    
    cout << b[t][n][n] << "\n";
    reverse(s.begin(), s.end());
    cout << s;

    //return 0;
}