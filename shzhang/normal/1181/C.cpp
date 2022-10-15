#include <cstdio>

using namespace std;

int n, m;
char grid[1005][1005];
int same_as_left[1005][1005];
int same_as_above[1005][1005];
int lastsamerow[1005][1005];

#define SUM(psum, top, left, bottom, right) (psum[bottom][right] \
        - psum[bottom][(left)-1] - psum[(top)-1][right] + psum[(top)-1][(left)-1])

#define SAME(top, left, bottom, right) (SUM(same_as_left, top, left+1, bottom, right) \
    == ((right) - (left)) * ((bottom) - (top) + 1) && SUM(same_as_above, top+1, left, bottom, right) \
    == ((right) - (left) + 1) * ((bottom) - (top)))

bool isflag(int top, int left, int bottom, int right)
{
    if (top < 1 || left < 1) return false;
    if ((bottom - top + 1) % 3) return false;
    int stripheight = (bottom - top + 1) / 3;
    //printf("%d %d %d %d\n", top, left, bottom, right);
    //printf("%d %d %d\n", SAME(top, left, top + stripheight - 1, right), SAME(top + stripheight, left, top + 2 * stripheight - 1, right), SAME(top + 2 * stripheight, left, top + 3 * stripheight - 1, right));
    return SAME(top, left, top + stripheight - 1, right) &&
           SAME(top + stripheight, left, top + 2 * stripheight - 1, right) &&
           SAME(top + 2 * stripheight, left, top + 3 * stripheight - 1, right) &&
           grid[top][left] != grid[top+stripheight][left] &&
           grid[top+stripheight][left] != grid[top + 2 * stripheight][left];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", grid[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) grid[i][j] = grid[i][j-1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            same_as_left[i][j] = (grid[i][j] == grid[i][j-1] ? 1 : 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            same_as_above[i][j] = (grid[i][j] == grid[i-1][j] ? 1 : 0);
        }
    }
    //printf("%d %d %d\n", (int)isflag(1, 1, 3, 2), (int)isflag(1, 3, 3, 3), (int)isflag(2, 1, 4, 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            lastsamerow[i][j] = (grid[i][j] == grid[i-1][j] ? lastsamerow[i-1][j] : i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            same_as_left[i][j] += same_as_left[i-1][j] + same_as_left[i][j-1] - same_as_left[i-1][j-1];
            same_as_above[i][j] += same_as_above[i-1][j] + same_as_above[i][j-1] - same_as_above[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int l = 0;
            int r = m;
            while (l < r) {
                int mid = (l + r) / 2 + 1;
                if (isflag(i - (i - lastsamerow[i][j] + 1) * 3 + 1, j - mid + 1, i, j)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            //printf("%d %d: %d\n", i, j, l);
            ans += l;
        }
    }
    printf("%d", ans);
    return 0;
}