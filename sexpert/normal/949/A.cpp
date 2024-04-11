#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c0 = 0, c1 = 0;
    string s;
    cin >> s;
    c0 = count(s.begin(), s.end(), '0');
    c1 = count(s.begin(), s.end(), '1');
    if(c1 >= c0) {
        cout << "-1\n";
        return 0;
    }
    int zes = c0 - c1, use = 0, pos = -1;
    vector<vector<int>> ans(zes);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            if(use < zes) {
                ans[use].push_back(i + 1);
                use++;
                continue;
            }
            if(pos == -1) {
                cout << "-1\n";
                return 0;
            }
            ans[pos].push_back(i + 1);
            pos--;
            continue;
        }
        pos++;
        if(pos == zes || pos >= use) {
            cout << "-1\n";
            return 0;
        }
        ans[pos].push_back(i + 1);
    }
    cout << zes << '\n';
    for(auto v : ans) {
        cout << v.size() << " ";
        for(auto x : v)
            cout << x << " ";
        cout << '\n';
    }
}