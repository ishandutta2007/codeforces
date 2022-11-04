#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 4e5 + 5;

int n, m, a[MAXN];
vector<int> cnt;

int main() {
    scanf("%d%d", &n, &m);
    m *= 8;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    
    sort(a + 1, a + n + 1);
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        ++t;
        if (i == n || a[i] != a[i + 1]) {
            cnt.push_back(t);
            t = 0;
        }
    }
    
    long long lim = 1;
    for (int i = 1; lim < (int) cnt.size() && i <= m / n; ++i) {
        lim <<= 1;
    }
    
    int sum = 0, ans = n;
    for (int l = 0, r = 0; l < (int) cnt.size(); ++l) {
        while (r < (int) cnt.size() && r - l + 1 <= lim) {
            sum += cnt[r++];
        }
        ans = min(ans, n - sum);
        sum -= cnt[l];
    }
    
    printf("%d\n", ans);
    
    return 0;
}