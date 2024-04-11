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

int a[N];
const int tme[6] = {3, 4, 5, 2, 1, 0};
int main() {
    init();
    ll s1, s2;
    cin >> s1 >> s2;
    if (s1 > s2) swap(s1, s2);
    ll a = s1;
    ll b = a;
    ll c = a;
    ll ans = 0;
    while (a < s2) {
        a = b;
        b = c;
        c = a + b - 1;
        ans++;
    }
    cout << ans;
    return 0;
}