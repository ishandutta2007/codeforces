#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int IINF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> ipair;

mt19937 rnd(228);

const int N = 202;

struct DP {
    DP* prv;
    int x, y;
};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif

    static DP d[6][6][2][N][N];
    d[0][0][0][0][0] = {&d[0][0][0][0][0], 0, 0};

    for (int m = 0; m < 5; ++m)
        for (int w1 = 0; w1 <= m; ++w1)
            for (int wl1 = 0; wl1 <= 1; ++wl1)
                for (int x = 0; x <= 200; ++x)
                    for (int y = 0; y <= 200; ++y) {
                        if (d[m][w1][wl1][x][y].prv == 0)
                            continue;
                        int w = (m == 4 ? 15 : 25);
                        DP *th = &d[m][w1][wl1][x][y];
                        if (x + w <= 200)
                            for (int i = 0; i <= w - 2 && y + i <= 200; ++i)
                                d[m+1][w1+1][1][x + w][y + i] = {th, w, i};
                        if (y + w <= 200)
                            for (int i = 0; i <= w - 2 && x + i <= 200; ++i)
                                d[m+1][w1][0][x + i][y + w] = {th, i, w};
                        for (int i = w + 1; x + i <= 200 && y + i - 2 <= 200; ++i)
                            d[m+1][w1+1][1][x + i][y + i - 2] = {th, i, i - 2};
                        for (int i = w + 1; x + i - 2 <= 200 && y + i <= 200; ++i)
                            d[m+1][w1][0][x + i - 2][y + i] = {th, i - 2, i};
                    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int m = -1, bw1 = -1, bwl1 = -1;
        for (int i = 1; i <= 5; ++i)
            for (int w1 = 0; w1 <= i; ++w1)
                for (int wl1 = 0; wl1 < 2; ++wl1) {
                    if (!d[i][w1][wl1][x][y].prv)
                        continue;
                    if (w1 < 3 && i - w1 < 3)
                        continue;
                    if (w1 > 3 || i - w1 > 3)
                        continue;
                    if (w1 == 3 && !wl1)
                        continue;
                    if (i - w1 == 3 && wl1)
                        continue;
                    int nb = w1 - (i - w1);
                    if (m == -1 || bw1 - (m - bw1) < nb) {
                        m = i;
                        bw1 = w1;
                        bwl1 = wl1;
                    }
                }
        if (m == -1) {
            printf("Impossible\n");
            continue;
        }
        DP *cur = &d[m][bw1][bwl1][x][y];
        printf("%d:%d\n", bw1, m - bw1);
        vector<ipair> res;
        for (int i = m; i > 0; --i) {
            res.push_back({cur->x, cur->y});
            cur = cur->prv;
        }
        reverse(res.begin(), res.end());
        for (ipair a : res)
            printf("%d:%d ", a.X, a.Y);
        printf("\n");
    }
}