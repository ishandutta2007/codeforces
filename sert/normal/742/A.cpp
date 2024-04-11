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
    init();
    int a[4] = {6, 8, 4, 2};
    int n;
    cin >> n;
    if (n == 0) cout << 1;
    else cout << a[n % 4];
    return 0;
}