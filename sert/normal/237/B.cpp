#include <cstdio>
#include <iostream>
#include <cstring>

#define ff first
#define ss second

const int N = 134;

using namespace std;

int n, m, p, mx, my;
int c[N];
int a[N][N];
bool ok;
int len;
pair <pair<int, int>, pair<int, int> > ans[N * N];

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < c[i]; j++)
            scanf("%d", &a[i][j]);

    for (int i = n - 1; i >= 0; i--)
        for (int j = c[i] - 1; j >= 0; j--) {
            mx = my = 0;
            ok = true;
            for (int ii = 0; ii < n && ok; ii++)
                for (int jj = 0; jj < c[ii] && ok; jj++) {
                    if (a[ii][jj] > a[mx][my]) {
                        mx = ii;
                        my = jj;
                    }
                    if (ii == i && jj == j) {
                        ok = false;
                        if (mx != ii || my != jj)
                            ans[len++] = make_pair(make_pair(mx + 1, my + 1), make_pair(ii + 1, jj + 1));
                        swap(a[mx][my], a[ii][jj]);
                    }
                }
        }

    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        printf("%d %d %d %d\n", ans[i].ff.ff, ans[i].ff.ss, ans[i].ss.ff, ans[i].ss.ss);

    return 0;
}