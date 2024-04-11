#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int orig = t.length();
    if(s.length() > t.length())
        swap(s, t);
    int n = s.length(), m = t.length(), match, ans = 1000000;
    for(int i = 0; i < m; i++) {
        match = 0;
        for(int j = 0; j < n && i + j < m; j++) {
            if(s[j] == t[i + j])
                match++;
            //cout << i << " " << j << " " << match << endl;
            ans = min(ans, orig - match);
        }
    }
    for(int i = 0; i < n; i++) {
        match = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == t[j - i])
                match++;
            ans = min(ans, orig - match);
        }
    }
    cout << ans << endl;
}