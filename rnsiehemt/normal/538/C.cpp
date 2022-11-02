#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))

int N, M;
int d[100005];
int h[100005];
int ans;

void fail() { printf("IMPOSSIBLE\n"); exit(0); }

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) scanf("%d%d", &d[i], &h[i]);
    for (int i = 0; i < M-1; i++) {
        if (std::abs(h[i+1]-h[i]) > d[i+1]-d[i]) fail();
        else ans = std::max(ans, std::max(h[i+1], h[i]) + (d[i+1]-d[i]-std::abs(h[i+1]-h[i]))/2);
    }
    ans = std::max(ans, h[0] + d[0]-1);
    ans = std::max(ans, h[M-1] + N-d[M-1]);
    printf("%d\n", ans);
}