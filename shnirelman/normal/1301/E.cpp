#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 500 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

char c[N][N];
int up[N][N];
int mx[N][N];
int mn[N][N];

int st[LOGN][LOGN][N][N];
int max2[N];

int get(int i1, int j1, int i2, int j2) {
    if(i2 <= i1 || j2 <= j1)
        return 0;
    int x = max2[i2 - i1], y = max2[j2 - j1];
    return max({st[x][y][i1][j1], st[x][y][i1][j2 - (1 << y)], st[x][y][i2 - (1 << x)][j1], st[x][y][i2 - (1 << x)][j2 - (1 << y)]});
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || c[i - 1][j] != c[i][j])
                up[i][j] = 1;
            else
                up[i][j] = up[i - 1][j] + 1;
        }
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << up[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mn = up[i][j];
            mx[i][j] = 1;
            for(int k = 1; k <= j; k++) {
                if(c[i][j - k] != c[i][j])
                    break;
                mn = min(mn, up[i][j - k]);
                if(mn > k) {
                    mx[i][j] = k + 1;
                }

            }
//            int mn = up[i][j];
//            int k = 1;
//            while(k <= j) {
//                mn = min(mn, up[i][j - k]);
//                if(mn < k)
//                    break;
//                k++;
//            }
//            mx[i][j] = k - 1;
        }
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << mx[i][j] << ' ';
//        }
//        cout << endl;
//    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(c[i][j] == 'R' && c[i][j + 1] == 'G' && c[i + 1][j] == 'Y' && c[i + 1][j + 1] == 'B') {
                int l = 1, r = min({i + 1, j + 1, n - i, m - j}) + 1;
                while(r - l > 1) {
                    int mid = (l + r) / 2;

                    if(mx[i][j] >= mid && mx[i][j + mid] >= mid && mx[i + mid][j] >= mid && mx[i + mid][j + mid] >= mid)
                        l = mid;
                    else
                        r = mid;
                }

                mn[i][j] = l;
            } else {
                mn[i][j] = 0;
            }
        }
    }
//
//    for(int i = 0; i < n - 1; i++) {
//        for(int j = 0; j < n - 1; j++) {
//            cout << mn[i][j] << ' ';
//        }
//        cout << endl;
//    }

    max2[1] = 0;
    for(int i = 2; i < N; i++) {
        max2[i] = max2[i / 2] + 1;
    }

    for(int x = 0; x < LOGN; x++) {
        for(int y = 0; y < LOGN; y++) {
            for(int i = 0; i + (1 << x) <= n; i++) {
                for(int j = 0; j + (1 << y) <= m; j++) {
                    if(x == 0 && y == 0)
                        st[x][y][i][j] = mn[i][j];
                    else if(x == 0)
                        st[x][y][i][j] = max(st[x][y - 1][i][j], st[x][y - 1][i][j + (1 << y - 1)]);
                    else //if(y == 0)
                        st[x][y][i][j] = max(st[x - 1][y][i][j], st[x - 1][y][i + (1 << x - 1)][j]);
//                    else
//                        st[x][y][i][j]
                }
            }
        }
    }

    for(int ind = 0; ind < q; ind++) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;

        i1--;
        j1--;

        int l = 0, r = n;
        while(r - l > 1) {
            int mid = (l + r) / 2;

            int i11 = i1 + mid - 1;
            int j11 = j1 + mid - 1;
            int i21 = i2 - mid;
            int j21 = j2 - mid;

            if(get(i11, j11, i21, j21) >= mid)
                l = mid;
            else
                r = mid;
        }

        cout << l * l * 4 << '\n';
    }
}