#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
const ll md = 1e9 + 7;

int n, mx = -1, cur = -1, ans;
pair <int, int> e[N], a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    a[n] = make_pair(2e9, 2e9 + 34);

    for (int i = 0; i < n; i++) {
        if (mx > a[i].second)
            ans++;
        cur = max(cur, a[i].second);
        if (a[i + 1].first > a[i].first)
            mx = max(mx, cur);
    }
    cout << ans;



    return 0;
}