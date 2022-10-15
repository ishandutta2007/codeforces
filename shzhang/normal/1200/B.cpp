#include <cstdio>
#include <algorithm>

using namespace std;

int absolute(int a)
{
    return a < 0 ? -a : a;
}

int h[105];

int main()
{
    int t, n, m, k;
    scanf("%d", &t);
    for (int data = 1; data <= t; data++) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) scanf("%d", h + i);
        int cur = 1;
        bool success = true;
        while (cur < n) {
            if (h[cur] >= h[cur+1] - k) {
                m += h[cur] - max(h[cur+1] - k, 0);
                h[cur] = max(h[cur+1] - k, 0);
            }
            if (h[cur] < h[cur+1]) {
                if (h[cur+1] - h[cur] > k) {
                    int amt = h[cur+1] - h[cur] - k;
                    if (m < amt) {
                        success = false;
                    }
                    m -= amt;
                }
            }
            if (!success) break;
            cur++;
        }
        if (success) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}