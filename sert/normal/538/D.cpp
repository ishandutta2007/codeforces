#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 200;

int n, dx, dy;
char a[N][N], f[N][N];
char b[N][N];
vector <pair<int, int> > c, d;
int cur, res;

int go(int y, int x) {
    if (min(x, y) < 0) return 0;
    if (max(x, y) >= n) return 0;
    if (a[y][x] == 'o') return 0;
    if (a[y][x] == '.') return -1;
    if (a[y][x] == 'x') return 1;
    exit(34);
}

void fuck(int y, int x) {
    //cerr << y << " " << x << " <-f\n";
    if (min(x, y) < 0) return;
    if (max(x, y) >= n) return;
    if (f[y][x] == 'o') return;
    f[y][x] = 'x';
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'o')
            f[i][j] = 'o';
        else
            f[i][j] = '.';
        if (a[i][j] == 'o')
            c.push_back(make_pair(i, j));
    }

    for (int i = 0; i < 2 * n - 1; i++)
        for (int j = 0; j < 2 * n - 1; j++)
            b[i][j] = '.';
    b[n - 1][n - 1] = 'o';

    for (int i = 0; i < 2 * n - 1; i++)
        for (int j = 0; j < 2 * n - 1; j++)
            if (i != n - 1 || j != n - 1) {
                dy = i - (n - 1);
                dx = j - (n - 1);
                cur = 0;
                for (int ii = 0; ii < c.size(); ii++) {
                    res = go(c[ii].first + dy, c[ii].second + dx);
                    if (res != 0) {
                        if (cur == 0) cur = res;
                        if (cur != res) {
                            cur = -1;
                        }
                    }
                }
                if (cur == 1) {
                    b[i][j] = 'x';
                    d.push_back(make_pair(i - n + 1, j - n + 1));
                    //cerr << i - n + 1 << " " << j - n + 1 << "\n";
                }
                else
                    b[i][j] = '.';
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 'o')
                for (int ii = 0; ii < d.size(); ii++)
                    fuck(i + d[ii].first, j + d[ii].second);

    /*cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << f[i][j];
        cout << "\n";
    }
    cout << "\n";*/

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != f[i][j]) {
                cout << "NO\n";
                return 0;
            }

    cout << "YES\n";
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++)
            cout << b[i][j];
        cout << "\n";
    }

    return 0;
}