#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int main() {
    //init();
    int n;
    int ans = -1;
    cin >> n;
    for (int i = 1; i <= n / i; i++)
        if (i * (n / i) == n)
            ans = i;
    cout << ans << " " << n / ans;
    return 0;
}