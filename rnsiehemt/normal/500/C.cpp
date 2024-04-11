#include <bits/stdc++.h>

int N, M;
int w[505]; int W;
int b[1005];
bool seen[505];
int ans;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &w[i]);
    for (int i = 0; i < M; i++) {
        scanf("%d", &b[i]); b[i]--;
        W = 0; std::fill(seen, seen+503, false);
        for (int j = i-1; j >= 0; j--) {
            if (b[j] == b[i]) break;
            else if (!seen[b[j]]) {
                seen[b[j]] = true;
                W += w[b[j]];
            }
        }
        ans += W;
    }
    printf("%d\n", ans);
}