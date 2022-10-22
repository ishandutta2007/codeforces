#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    int cnt = INF;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            ans += max(0, 2 - cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }

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