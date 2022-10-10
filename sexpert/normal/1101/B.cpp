#include <bits/stdc++.h>
using namespace std;

string cutAfter(string s, char c) {
    int i = 0;
    for(;i < s.length(); i++) {
        if(s[i] == c)
            break;
    }
    i++;
    string t = "";
    for(;i < s.length();i++)
        t += s[i];
    return t;
}

string cutTo(string s, char c) {
    string t = "";
    int i = s.length() - 1;
    for(;i >= 0; i--) {
        if(s[i] == c)
            break;
    }
    for(int j = 0; j < i; j++)
        t += s[j];
    return t;
}

int main() {
    string s, t = "";
    cin >> s;
    set<char> st({'|', '[', ']', ':'});
    for(int i = 0; i < s.length(); i++) {
        if(st.count(s[i]))
            t += s[i];
    }
    t = cutAfter(cutTo(cutAfter(t, '['), ']'), ':');
    if(t.find(':') == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    t = cutTo(t, ':');
    int ans = 4;
    for(auto c : t) {
        if(c == '|')
            ans++;
    }
    cout << ans << endl;
}