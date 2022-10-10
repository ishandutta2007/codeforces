#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> positions[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        positions[s[i] - 'a'].push_back(i + 1);

    int q;
    cin >> q;
    while(q--) {
        vector<int> ct(26);
        string t;
        cin >> t;
        for(auto c : t)
            ct[c - 'a']++;
        int ans = 0;
        for(int i = 0; i < 26; i++)
            if(ct[i]) ans = max(ans, positions[i][ct[i] - 1]);
        cout << ans << '\n';
    }
}