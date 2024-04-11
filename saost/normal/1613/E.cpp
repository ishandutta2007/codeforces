#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
#define inside(u, v) (u >= 0 && u < m && v >= 0 && v < n)
using namespace std;
const int N = 1000005;
const int Gx[4] = {0, 1, 0, -1}, Gy[4] = {1, 0, -1, 0};
int t, m, n, Lx, Ly;
string s[N];

int getDeg(int x, int y) {
    int ans = 0;
    REP(i, 0, 4) {
        int u = x + Gx[i];
        int v = y + Gy[i];
        if (inside(u, v) && s[u][v] == '.') ++ans;
    }
    return ans;
}

void DFS(int x, int y) {
    if (s[x][y] != 'L') s[x][y] = '+';
    REP(i, 0, 4) {
        int u = x + Gx[i];
        int v = y + Gy[i];
        if (inside(u, v) && s[u][v] == '.' && getDeg(u, v) <= 1)
            DFS(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> m >> n;
        REP(i, 0, m) {
            cin >> s[i];
            REP(j, 0, n) if (s[i][j] == 'L') {
                Lx = i; Ly = j;
            }
        }
        DFS(Lx, Ly);
        REP(i, 0, m) cout << s[i] << '\n';
    }
}