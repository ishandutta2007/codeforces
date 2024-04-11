#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2013;
const int K = 9;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int mx = n - 1;
    for(int i = n - 1; i >= 0 && n - i - 1 <= k; i--) {
        if(s[mx] < s[i]) {
            mx = i;
        }
    }

//    cout << "mx " << mx << endl;

    int mx2 = (mx == 0);
    int cur = 0;
    for(int i = (mx == 0); i < n && cur + n - mx - 1 <= k; i++) {
        if(i == mx)
            continue;
        if(s[mx2] < s[i])
            mx2 = i;
        cur++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += (s[i] - '0') * 11;

    ans -= (s[mx] - '0') * 10;
    ans -= (s[mx2] - '0');

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}