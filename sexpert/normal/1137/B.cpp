#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int bor(const string& s) {
    vi p(s.size());
    for(int i = 1; i < s.size(); i++) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p[s.size() - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int ct0 = 0, ct1 = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0')
            ct0++;
        else
            ct1++;
    }
    string ans = "";
    int b = bor(t);
    string sub = t.substr(b);
    int s0 = 0, s1 = 0;
    for(int i = 0; i < sub.length(); i++) {
        if(sub[i] == '0')
            s0++;
        else
            s1++;
    }
    int t0 = 0, t1 = 0;
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == '0')
            t0++;
        else
            t1++;
    }
    if(t1 > ct1 || t0 > ct0) {
        cout << s << endl;
        return 0;
    }
    ans += t;
    ct0 -= t0;
    ct1 -= t1;
    while(ct0 >= s0 && ct1 >= s1) {
        ans += sub;
        ct0 -= s0;
        ct1 -= s1;
    }
    while(ct0 > 0) {
        ans += '0';
        ct0--;
    }
    while(ct1 > 0) {
        ans += '1';
        ct1--;
    }
    cout << ans << endl;
}