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
    int a2, a3, a5, a6;
    cin >> a2 >> a3 >> a5 >> a6;
    int x = min(a2, min(a5, a6));
    cout << min(a2 - x, a3) * 32 + x * 256;
    return 0;
}