/// problems codeforces : https://codeforces.com/contest/600/status/F
#include <iostream>
using namespace std;
const int N = 2e3+5, M = 1e5+5;
int n1, n, m, res, u[M], v[M], f[N], nxt[N][N];  /// nxt[i][j] : dinh lien voi i co mau j
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n1 >> n >> m;
    n += n1;
    for(int i=1; i<=m; i++) {
        cin >> u[i] >> v[i];
        v[i] += n1;
        f[u[i]]++; f[v[i]]++;
    }
    for(int i=1; i<=n; i++) res = max(res, f[i]);
    cout << res << '\n';
    for(int i=1; i<=m; i++) {
        int c1 = 1, c2 = 1, c4 = 1;
        while (nxt[u[i]][c4] || nxt[v[i]][c4]) c4++;
        if (c4 <= res) {
            nxt[u[i]][c4] = v[i];
            nxt[v[i]][c4] = u[i];
            continue;
        }
        while (nxt[u[i]][c1]) c1++;
        while (nxt[v[i]][c2]) c2++;
        nxt[u[i]][c1] = v[i];
        nxt[v[i]][c2] = u[i];
        if (c1 == c2) continue;
        for(int c3 = c2, x = v[i]; x; x = nxt[x][c3], c3 ^= c1^c2)
            swap(nxt[x][c1], nxt[x][c2]);
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=res; j++) if (nxt[u[i]][j] == v[i]) {
            cout << j << ' ';
            break;
        }
    }
}