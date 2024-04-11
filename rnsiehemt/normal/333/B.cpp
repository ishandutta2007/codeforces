#include <cstdio>
#include <algorithm>

int N, M;
bool xban[1010];
bool yban[1010];
int count[260];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y; scanf("%d%d", &x, &y);
        xban[x] = true;
        yban[y] = true;
    }
    
    for (int j = 0; j < (1 << 8); j++) {
        for (int i = 0; i < 8; i++)
            if ((j & (1 << i)))
                count[j]++;
    }
    
    int ans = 0;

    for (int i = 2; i < N+1-i; i++) {
        int best = 0;
        for (int j = 0; j < (1 << 8); j++) {
            bool a = (j & (1 << 0));
            bool b = (j & (1 << 1));
            bool c = (j & (1 << 2));
            bool d = (j & (1 << 3));
            bool e = (j & (1 << 4));
            bool f = (j & (1 << 5));
            bool g = (j & (1 << 6));
            bool h = (j & (1 << 7));
            if ((a || b) && xban[i]) continue;
            if ((c || d) && yban[i]) continue;
            if ((e || f) && xban[N+1-i]) continue;
            if ((g || h) && yban[N+1-i]) continue;
            if ((a || g) && (c || e)) continue;
            if ((b || h) && (d || f)) continue;
            if ((a && b) || (c && d) || (e && f) || (g && h)) continue;
            best = std::max(best, count[j]);
        }
        ans += best;
    }

    if (N % 2 == 1) {
        if (!xban[N/2+1] || !yban[N/2+1]) ans++;
    }

    printf("%d\n", ans);
}