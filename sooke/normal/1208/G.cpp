#include <cstdio>
#include <algorithm>

const int N = 1e6 + 5;

int n, k, p, pri[N], phi[N];
long long ans;
bool vis[N];

void sieve(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            pri[p++] = i; phi[i] = i - 1;
        }
        for (int j = 0; j < p; j++) {
            int k = i * pri[j];
            if (k > n) { break; }
            vis[k] = true;
            if (i % pri[j] == 0) {
                phi[k] = phi[i] * pri[j]; break;
            } else {
                phi[k] = phi[i] * phi[pri[j]];
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    if (k == 1) {
        printf("3\n"); return 0;
    } sieve(n); k += 2;
    std::sort(phi + 1, phi + n + 1);
    for (int i = 1; i <= k; i++) { ans += phi[i]; }
    printf("%I64d\n", ans);
    return 0;
} ////