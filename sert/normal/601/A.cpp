#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000;

int n, m;
int d[N];
bool q;
bool u[N][N];
queue <int> qq;
int x, y;
int xx, yy, v1, v2;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    /*if (m == 0 || m == (n * (n - 1)) / 2) {
        cout << -1;
        return 0;
    }*/
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        u[v1][v2] = u[v2][v1] = true;
    }
    q = !u[0][n - 1];

    for (int i = 0; i < n; i++) d[i] = -1;
    d[0] = 0;
    qq.push(0);
    while (!qq.empty()) {
        x = qq.front();
        qq.pop();
        for (int i = 0; i < n; i++)
        if (u[x][i] == q && d[i] == -1) {
            d[i] = d[x] + 1;
            qq.push(i);
        }
    }

    cout << d[n - 1];

    return 0;
}