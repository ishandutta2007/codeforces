#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ != 4 && __GNUC_MINOR__ != 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const ll INF = 1e9 + 34;

int main() {
    //init();
    int n, k;
    cin >> n >> k;

    int p = 0;
    while (5 * p * (p + 1) / 2 + k <= 240)
        p++;
    cout << min(n, p - 1);

    return 0;
}