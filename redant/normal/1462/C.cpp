#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

string solve() {
    int nxt = 9;
    string s;
    while (n && nxt) {
        if (n >= nxt) {
            s = (char) ('0' + nxt) + s;
            n -= nxt;
        }
        nxt--;
    }
    if (!n) return s;
    return "-1";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        cout << solve() << "\n";
    }
    
    return 0;
}