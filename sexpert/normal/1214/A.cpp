#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, ans = 1000000000;
    cin >> a >> b >> c;
    while(a >= 0) {
        ans = min(ans, a % (5*c));
        a -= b;
    }
    cout << ans << '\n';
}