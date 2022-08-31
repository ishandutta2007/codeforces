#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 105;
string s[MX];
int n, m;

int solve() {
    int r = 0;
    REP(j, m-1)
        r += s[n-1][j] == 'D';
    REP(i, n-1)
        r += s[i][m-1] == 'R';
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>s[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}