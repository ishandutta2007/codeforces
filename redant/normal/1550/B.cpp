#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, a, b;
string s;

int solve() {
    int c[2] = {0};
    REP(i, n) {
        if (i == 0 || s[i] != s[i-1])
            c[s[i]-'0']++;
    }
    int r = n * a;
    if (b >= 0)
        return r + n * b;
    // cout << c[0] << " & " << c[1] << endl;
    return r + b * min(c[0]+(c[1]?1:0), c[1]+(c[0]?1:0));
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}