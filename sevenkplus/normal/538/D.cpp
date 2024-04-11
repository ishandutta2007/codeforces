#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 55

string a[N]; int n;
bool b[N][N];
int c[N*2][N*2];

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int dx = -n; dx <= n; dx ++)
        for (int dy = -n; dy <= n; dy ++) {
            bool F = 1;
            for (int i = 0; i < n; i ++)
                for (int j = 0; j < n; j ++) if (a[i][j] == 'o') {
                    int x = i+dx;
                    int y = j+dy;
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (a[x][y] == '.') F = 0;
                }
            if (!F) continue;
            c[dx+n][dy+n] = 1;
            for (int i = 0; i < n; i ++)
                for (int j = 0; j < n; j ++) if (a[i][j] == 'o') {
                    int x = i+dx;
                    int y = j+dy;
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (a[x][y] == 'x') b[x][y] = 1;
                }
        }
    bool F = 1;
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < n; j ++) 
            if (a[i][j] == 'x' && !b[i][j]) F = 0;
    puts (F?"YES":"NO");
    if (F) {
        for (int dx = -n+1; dx <= n-1; dx ++) {
            for (int dy = -n+1; dy <= n-1; dy ++) {
                if (dx == 0 && dy == 0) putchar('o'); else
                if (c[dx+n][dy+n]) putchar('x'); else putchar('.');
            }
            puts ("");
        }
    }
    return 0; 
}