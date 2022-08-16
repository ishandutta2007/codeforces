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

string solve() {
    int r[2] = {0};
    int p = 0;
    if (n&1 && s[n/2]=='0') {
        r[p]++; p=1-p;
    }
    REP(i, n) {
        if (n&1 && i == n/2 && s[i]=='0')
            continue;
        if (s[i] == '0') {
            r[p]++; p=1-p;
            if (2*i < n) p=1-p;
        }
    }
    if (r[0] == r[1]) return "DRAW";
    if (r[0] < r[1]) return "ALICE";
    return "BOB";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}