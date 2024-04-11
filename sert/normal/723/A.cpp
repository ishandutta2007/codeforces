#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;

int main() {
    init();
    ll a, b, c;
    cin >> a >> b >> c;
    cout << max(a, max(b, c)) - min(a, min(b, c));

    return 0;
}