#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 34;

int x, w, n, len, la, l, r, m, mn;
pair <int, int> a[N];
pair <int, int> ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &w);
        a[len++] = make_pair(x + w, x - w);
        mn = min(mn, x - w);
    }
    sort(a, a + len);

    ans[la++] = make_pair(mn - 1, 0);

    for (int i = 0; i < len; i++) {
        l = 0;
        r = la;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (ans[m].first <= a[i].second)
                l = m;
            else
                r = m;
        }
        ans[la].second = max(ans[la - 1].second, ans[l].second + 1);
        ans[la].first = a[i].first;
        la++;
    }
    printf("%d", ans[la - 1].second);
    return 0;
}