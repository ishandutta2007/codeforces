#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 4;
typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 9;
const ll p1 = 997;
const ll p2 = 2011;

ll n, k, ans, x;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> k;
    ans = n;
    while (n--) {
        cin >> x;
        if (x > k)
            ans++;
    }
    cout << ans;

    return 0;
}