#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

/*

*/

void solve() {
    int n, b, x, y;
    cin >> n >> b >> x >> y;

    vector<int> a(n + 1, 0);
    li sum = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] + x <= b) {
            a[i] = a[i - 1] + x;
        } else {
            a[i] = a[i - 1] - y;
        }

        sum += a[i];
    }

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}