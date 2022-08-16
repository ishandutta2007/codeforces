#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;

LL solve() {
    n = s.length();
    LL r = 0;
    int st = 0, nxt = -1;
    REP(i, n) {
        if (nxt != -1 && s[i] != '?' && s[i] != '0' + nxt) {
            nxt = s[i] - '0';
            st = i;
            while (st > 0 && s[st-1] == '?') st--;
        }

        if (s[i] != '?') nxt = s[i] - '0';

        if (nxt != -1)
            nxt = 1 - nxt;
        r += i - st + 1;
        // cout << i << ", " << st << ", " << nxt << endl;
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}