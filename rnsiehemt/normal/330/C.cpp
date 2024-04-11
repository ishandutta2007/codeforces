#include <cstdio>

int N;
char g[105][105];

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++) scanf(" %s", g[y]);
    
    bool q = true;
    for (int y = 0; y < N; y++) {
        bool f = false;
        for (int x = 0; x < N; x++) if (g[y][x] == '.') f = true;
        if (!f) q = false;
    }

    if (q) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (g[y][x] == '.') {
                    printf("%d %d\n", y+1, x+1);
                    break;
                }
            }
        }
        return 0;
    }

    q = true;
    for (int x = 0; x < N; x++) {
        bool f = false;
        for (int y = 0; y < N; y++) if (g[y][x] == '.') f = true;
        if (!f) q = false;
    }

    if (q) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (g[y][x] == '.') {
                    printf("%d %d\n", y+1, x+1);
                    break;
                }
            }
        }
        return 0;
    }

    printf("-1\n");
}