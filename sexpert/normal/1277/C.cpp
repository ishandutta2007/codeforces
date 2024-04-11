#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    vector<int> ans;
    string s;
    cin >> s;
    for(int i = 0; i + 2 < s.size(); i++) {
        string t = s.substr(i, 3);
        if(t == "two") {
            if(s.substr(i + 2, 3) == "one") { 
                ans.push_back(i + 3);
                i += 2;
                continue;
            }
            ans.push_back(i + 2);
            i++;
            continue;
        }
        if(t == "one") {
            ans.push_back(i + 2);
            i++;
            continue;
        }
    }
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}