#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

/*
*/

void solve() {
    li n;
    cin >> n;

    li lcm = 1;
    int ans = n % M;
    for(int i = 2; lcm <= n; i++) {
        ans = (ans + n / lcm) % M;

        lcm = lcm * i / __gcd(lcm, i * 1ll);
    }

    cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}