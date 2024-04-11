#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string ass = "abacaba";

int asscount(string s) {
    int ct = 0;
    for(int i = 0; i + 6 < s.size(); i++)
        if(s.substr(i, 7) == ass)
            ct++;
    return ct;
}

bool match(string s, int st) {
    for(int i = 0; i < 7; i++) {
        if(s[st + i] != '?' && s[st + i] != ass[i])
            return false;
    }
    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ict = asscount(s);
    if(ict > 2) {
        cout << "No\n";
        return;
    }
    if(ict == 1) {
        cout << "Yes\n";
        for(auto &c : s)
            if(c == '?') c = 'z';
        cout << s << '\n';
        return;
    }
    for(int i = 0; i + 6 < n; i++) {
        if(match(s, i)) {
            string t = s;
            for(int j = 0; j < 7; j++)
                if(t[i + j] == '?') t[i + j] = ass[j];
            if(asscount(t) > 1)
                continue;
            cout << "Yes\n";
            for(auto &c : t)
                if(c == '?') c = 'z';
            cout << t << '\n';
            return;
        }
    }
    cout << "No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}