#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;
int n, k, ans, a[N];
int main() {
    init();
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        while (a[i] + a[i - 1] < k) {
            a[i]++;
            ans++;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}