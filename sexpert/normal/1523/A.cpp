#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> mv;
    k = min(k, n);
    for(int i = 0; i < k; i++) {
        mv.clear();
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            if(j + 1 < n && s[j + 1] == '1')
                cnt++;
            if(j - 1 >= 0 && s[j - 1] == '1')
                cnt++;
            if(cnt == 1)
                mv.push_back(j);
        }
        for(auto j : mv)
            s[j] = '1';
    }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}