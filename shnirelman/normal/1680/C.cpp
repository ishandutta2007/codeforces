#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> p0(n + 1, 0), p1(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p0[i + 1] = p0[i] + (s[i] == '0');
        p1[i + 1] = p1[i] + (s[i] == '1');
    }

    int ans = p1[n];
    for(int i = 0; i < n; i++) {
        int l = 0, r = i + 1;
        while(r - l > 1) {
            int m = (l + r) / 2;

            int x = p0[i + 1] - p0[m];
            int y = p1[n] - p1[i + 1] + p1[m];

            if(x < y)
                r = m;
            else
                l = m;
        }

        ans = min(ans, max(p0[i + 1] - p0[l], p1[n] - p1[i + 1] + p1[l]));
    }

    cout << ans << endl;
}

int main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}