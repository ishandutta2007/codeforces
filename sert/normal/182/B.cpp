#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
const long long N = 1e5 + 34;
typedef long long ll;
ll n, d, cur = 1, x, ans;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> d >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (cur != 1)
            ans += d + 1 - cur;
        cur = x % d + 1;
    }
    cout << ans;
}