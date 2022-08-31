#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;
int k;

string solve() {
    string r = "";
    int a = 0, b = 0;
    int n = 0;
    for (char c : s)
        if (c == '?') a++;
        else if (c == '*') b++;
        else n++;
    if (k > n) {
        if( b == 0) return "Impossible";
        bool got = false;
        char pc;
        for (char c : s)
            if (c == '?') {}
            else if (c == '*') {
                if (!got)
                    REP(i, k - n) r += pc;
                got = true;
            } 
            else {
                r += c;
                pc = c;
            }
        return r;
    }
    // k <= n
    int rm = n - k;
    if (rm > (a + b)) return "Impossible";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') {}
        else if (s[i] == '*') {}
        else {
            if (i + 1 < s.length() && (s[i+1]=='*'||s[i+1]=='?') && rm > 0) {
                --rm;
            } else {
                r += s[i];
            }
        }
    }
    return r; 
}

int main() {
    setIO();
    cin>>s>>k;
    cout<<solve()<<"\n";    
    return 0;
}