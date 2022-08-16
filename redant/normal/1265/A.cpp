#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string solve(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] != '?' && s[i] == s[i+1])
            return "-1";
        if (s[i] == '?') {
            for (char c = 'a'; c <= 'c'; c++)
                if ((i == 0 || c != s[i-1]) && (i+1 == n || s[i+1] != c)) {
                    s[i] = c;
                    break;
                }
        }    
    }
    return s;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
    
    return 0;
}