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

int solve() {
    int c[2] = {0};
    for (char ch : s)
        c[ch-'0']++;
    int r = min(c[0], c[1]);
    if (c[0] != c[1])
        return r;
    return r - 1;
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