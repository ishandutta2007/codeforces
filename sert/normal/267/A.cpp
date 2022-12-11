#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long n, a, b, ans;

int main() {
   // freopen("a.in", "r", stdin);
    cin >> n;
    while (n --> 0) {
        cin >> a >> b;
        ans = 0;
        while (a > 0 && b > 0) {
            if (a < b) swap(a, b);
            ans += a / b;
            a %= b;
        }
        cout << ans << "\n";
    }
    return 0;
}