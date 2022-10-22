#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string res = s;
    int ans = 1;
    for(int k = 2; k <= n; k++) {
        string s1 = s.substr(k - 1, n - k + 1);
        string s2 = s.substr(0, k - 1);

        if((n - k) % 2 == 0) {
            reverse(s2.begin(), s2.end());
        }

        string t = s1 + s2;

        if(t < res) {
            res = t;
            ans = k;
        }
    }

    cout << res << endl << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}