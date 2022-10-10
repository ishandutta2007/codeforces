#include <bits/stdc++.h>
using namespace std;

string mix(string s, string t, char c) {
    int n = s.size()/2;
    vector<int> v1 = {-1}, v2 = {-1};
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == c)
            v1.push_back(i);
        if(t[i] == c)
            v2.push_back(i);
    }
    string ans;
    for(int i = 0; i < n; i++) {
        for(int j = v1[i] + 1; j < v1[i + 1]; j++)
            ans += s[j];
        for(int j = v2[i] + 1; j < v2[i + 1]; j++)
            ans += t[j];
        ans += c;
    }
    for(int j = v1[n] + 1; j < 2 * n; j++)
        ans += s[j];
    for(int j = v2[n] + 1; j < 2 * n; j++)
        ans += t[j];
    return ans;
}

void solve() {
    vector<string> s0, s1;
    int n;
    cin >> n;
    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        int cnt_0 = 0;
        for(auto &c : s) {
            if(c == '0')
                cnt_0++;
        }
        if(cnt_0 >= n)
            s0.push_back(s);
        else
            s1.push_back(s);
    }
    if(s0.size() >= 2)
        cout << mix(s0[0], s0[1], '0') << '\n';
    else
        cout << mix(s1[0], s1[1], '1') << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}