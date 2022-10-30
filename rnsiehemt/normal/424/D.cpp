#include <cstdio>
#include <algorithm>
#include <set>

int Y, X, aim;
int flat, up, down;
int a[305][305];
int row[305][305];
int rowb[305][305];
int col[305][305];
int colb[305][305];
int best = 1999999999;
int besty1, besty2, bestx1;

int cost(int p, int q) {
    if (p > q) return down;
    else if (p == q) return flat;
    else /* if (p < q) */ return up;
}

int main()
{
    scanf("%d%d%d", &Y, &X, &aim);
    scanf("%d%d%d", &flat, &up, &down);
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++)
        scanf("%d", &a[y][x]);

    for (int y = 0; y < Y; y++) {
        for (int x = 1; x < X; x++) {
            row[y][x] = row[y][x-1] + cost(a[y][x-1], a[y][x]);
            rowb[y][x] = rowb[y][x-1] + cost(a[y][x], a[y][x-1]);
        }
    }
    for (int x = 0; x < X; x++) {
        for (int y = 1; y < Y; y++) {
            col[y][x] = col[y-1][x] + cost(a[y-1][x], a[y][x]);
            colb[y][x] = colb[y-1][x] + cost(a[y][x], a[y-1][x]);
        }
    }
    
    for (int y1 = 0; y1 < Y; y1++) {
        for (int y2 = y1+2; y2 < Y; y2++) {
            std::set<int> s;

            for (int x1 = X-3; x1 >= 0; x1--) {
                s.insert(row[y1][x1+2] + rowb[y2][x1+2] + (col[y2][x1+2] - col[y1][x1+2]));
                int search = aim + row[y1][x1] + rowb[y2][x1] - (colb[y2][x1] - colb[y1][x1]);
                std::set<int>::iterator r = s.lower_bound(search);
                std::set<int>::iterator l = r; if (l != s.begin()) l--;
                if (l != s.end() && std::abs(*l - search) < best) {
                    best = std::abs(*l - search);
                    besty1 = y1; besty2 = y2; bestx1 = x1;
                }
                if (r != s.end() && std::abs(*r - search) < best) {
                    best = std::abs(*r - search);
                    besty1 = y1; besty2 = y2; bestx1 = x1;
                }
            }
        }
    }
    
    int bestx2;
    for (bestx2 = bestx1+2; bestx2 < X; bestx2++) {
        int cur = row[besty1][bestx2] - row[besty1][bestx1] +
                  col[besty2][bestx2] - col[besty1][bestx2] +
                  rowb[besty2][bestx2] - rowb[besty2][bestx1] +
                  colb[besty2][bestx1] - colb[besty1][bestx1];
        if (std::abs(cur - aim) == best) break;
    }

    //printf("%d\n", best);
    printf("%d %d %d %d\n", besty1+1, bestx1+1, besty2+1, bestx2+1);
}