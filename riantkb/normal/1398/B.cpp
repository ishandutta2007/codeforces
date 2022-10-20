#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        string s;
        cin >> s;
        vector<int> v;
        int c = 0;
        for (auto& i : s) {
            if (i == '1') {
                ++c;
            }
            else {
                if (c > 0) v.push_back(c);
                c = 0;
            }
        }
        if (c > 0) {
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < (int)v.size(); i += 2) {
            ans += v[i];
        }
        cout << ans << '\n';
    }

    return 0;
}