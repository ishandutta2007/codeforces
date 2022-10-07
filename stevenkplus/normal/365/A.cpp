#include <cstdio>
bool vis[100];
int ans = 0;
int N, K;
int main() {
scanf("%d %d", &N, &K);
for(int i = 0; i < N; ++i) {
int nxt;
scanf("%d", &nxt);
for(int j = 0; j <=K; ++j) vis[j] = false;
while (nxt) {
vis[nxt % 10] = true;
nxt /= 10;
}
bool good = true;
for(int j = 0; j <= K; ++j) if (!vis[j]) {
good = false;
}
if (good) ++ans;
}
printf("%d\n", ans);
return 0;
}