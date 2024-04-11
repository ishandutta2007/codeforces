#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    string s;
    cin >> a >> b >> s;
    int n = a + b;
    vector<int> ps;
    for(int i = 0; i < n - 1 - i; i++) {
        if(s[i] != '?') {
            if(s[n - 1 - i] != '?' && s[n - 1 - i] != s[i]) {
                cout << "-1\n";
                return;
            }
            s[n - 1 - i] = s[i];
        }
        s[i] = s[n - 1 - i];
        if(s[i] == '?')
            ps.push_back(i);
    }
    for(auto &c : s) {
        if(c == '0')
            a--;
        if(c == '1')
            b--;
    }
    if(a < 0 || b < 0) {
        cout << "-1\n";
        return;
    }
    if(n % 2 && s[n/2] == '?') {
        if(a % 2) {
            s[n/2] = '0';
            a--;
        }
        else {
            s[n/2] = '1';
            b--;
        }
    }
    if(a % 2 || b % 2) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < ps.size(); i++) {
        if(i < a/2)
            s[ps[i]] = s[n - ps[i] - 1] = '0';
        else
            s[ps[i]] = s[n - ps[i] - 1] = '1';
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