#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn2(i, n) for (i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

char a[100][100];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int sx = 0, sy = 0;
    int tx = 0, ty = 0;
    forn (i, n) {
        cin >> a[i];
        forn (j, m) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'E') {
                tx = i;
                ty = j;
            }
        }
    }
    string s;
    cin >> s;
    int k = s.size();
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int p[4];
    int ans = 0;
    forn2 (p[0], 4) {
        forn2 (p[1], 4) {
            forn2 (p[2], 4) {
                forn2 (p[3], 4) {
                    bool ok = true;
                    forn (i, 4) {
                        forn (j, i) {
                            if (p[i] == p[j]) {
                                ok = false;
                            }
                        }
                    }
                    if (!ok) {
                        continue;
                    }
                    int cx = sx, cy = sy;
                    bool was = false;
                    forn (i, k) {
                        int x = cx + dx[p[s[i] - '0']];
                        int y = cy + dy[p[s[i] - '0']];
                        if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#') {
                            ok = false;
                            break;
                        }
                        cx = x;
                        cy = y;
                        if (x == tx && y == ty) {
                            was = true;
                            break;
                        }
                    }
                    if (!was) {
                        ok = false;
                    }
                    ans += ok;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}