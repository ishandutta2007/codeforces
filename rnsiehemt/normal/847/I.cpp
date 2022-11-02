#include <bits/stdc++.h>

const int maxc = 255;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int Y, X, seen[maxc][maxc];
long long q, p, v[maxc][maxc];
char g[maxc][maxc];

void go(int sy, int sx, long long sa) {
    int k = sy * X + sx + 1;
    //printf("%d %d %d\n", sy, sx, k);
    std::queue<std::tuple<int, int, long long>> q;
    q.emplace(sy, sx, sa);
    seen[sy][sx] = k;
    while (!q.empty()) {
        int y, x;
        long long a;
        std::tie(y, x, a) = q.front();
        q.pop();

        v[y][x] += a;

        a /= 2;
        if (a) {
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (0 <= ny && ny < Y && 0 <= nx && nx < X && g[ny][nx] != '*' && seen[ny][nx] != k) {
                    seen[ny][nx] = k;
                    q.emplace(ny, nx, a);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%lld%lld", &Y, &X, &q, &p);
    for (int y = 0; y < Y; y++) {
        scanf(" %s", g[y]);
    }
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if ('A' <= g[y][x] && g[y][x] <= 'Z') {
                go(y, x, (g[y][x] - 'A' + 1) * q);
                //printf("after doing %d %d\n", y, x);
                /*for (int y = 0; y < Y; y++) {
                    for (int x = 0; x < X; x++) {
                        printf("%lld%c", v[y][x], " \n"[x == X-1]);
                    }
                }*/
            }
        }
    }
    int count = 0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            //printf("%lld%c", v[y][x], " \n"[x == X-1]);
            if (v[y][x] > p) {
                count++;
            }
        }
    }
    printf("%d\n", count);
}