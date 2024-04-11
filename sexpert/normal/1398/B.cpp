#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        s += '0';
        vector<int> mv;
        int cnt = 0;
        for(auto &c : s) {
            if(c == '1')
                cnt++;
            else {
                mv.push_back(cnt);
                cnt = 0;
            }
        }
        sort(mv.rbegin(), mv.rend());
        int ans = 0;
        for(int i = 0; i < mv.size(); i += 2)
            ans += mv[i];
        cout << ans << '\n';
    }
}