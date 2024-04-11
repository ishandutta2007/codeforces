#include <cstdio>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxN = 4000005;

int n, x, y, max, pos, a[maxN];
long long ans = 5e18, now, cnt[maxN], sum[maxN];

int main() {
    n = read(); x = read(); y = read();   
    for (int i = 1; i <= n; i++) { a[i] = read(); cnt[a[i]]++; sum[a[i]] += a[i]; }
    max = *std::max_element(a + 1, a + n + 1); max <<= 1;
    for (int i = 2; i <= max << 1; i++) { cnt[i] += cnt[i - 1]; sum[i] += sum[i - 1]; }
    for (int i = 2; i <= max; i++) {
        for (int l = 0, r = i; l < max; l = r, r = l + i) {
            pos = std::max(l, r - (x - 1) / y - 1);
            now += x * (cnt[pos] - cnt[l]) + y * (r * (cnt[r] - cnt[pos]) - (sum[r] - sum[pos]));
        }
        ans = std::min(ans, now); now = 0;
    }
    printf("%I64d\n", ans);
    return 0;
} //