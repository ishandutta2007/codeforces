#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 113;
const int LOGN = 20;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

mt19937 rnd(3666);
void solve() {
    li n;
    cin >> n;

    if(n % 2050 != 0) {
        cout << -1 << endl;
    } else {
        n /= 2050;
        int cnt = 0;
        while(n > 0) {
            cnt += n % 10;
            n /= 10;
        }

        cout << cnt << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}