#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(300);
    for(auto c : s)
        cnt[c]++;
    int n = s.size();
    int ans = n;
    for(char c = '0'; c <= '9'; c++) {
        ans = min(ans, n - cnt[c]);
    }
    for(char c1 = '0'; c1 <= '9'; c1++) {
        for(char c2 = '0'; c2 <= '9'; c2++) {
            int cur = 0;
            for(auto c : s) {
                if(c == ((cur & 1) ? c1 : c2))
                    cur++;
            }
            if(cur % 2)
                cur--;
            ans = min(ans, n - cur);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}