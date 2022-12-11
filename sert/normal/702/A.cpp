#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
const int N = 1e6 + 34;
const int INF = 1e9 + 34;
typedef long long ll;

int cur, ans, n, a[N];

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cur = ans = 1;
    a[n] = -INF;
    for (int i = 1; i <= n; i++)
        if (a[i] > a[i - 1])
            cur++;
        else {
            ans = max(ans, cur);
            cur = 1;
        }

    cout << ans;

    return 0;
}