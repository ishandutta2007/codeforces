#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;
bool vis[101][101];

bool go(int i, int sm) {
    if (i == n) return sm == 0;
    if (sm < 0 || 2 * sm > n) return false;
    if (vis[i][sm]) return false;
    vis[i][sm] = true;
    if (s[i] == '(') return go(i+1, sm+1);
    else if (s[i] == ')') return go(i+1, sm-1);
    else return go(i+1, sm-1) || go(i+1, sm+1);
}

int solve() {
    n = s.length();
    if (n&1) return false;
    REP(i, n) REP(j, (n/2)+1) vis[i][j] = false;
    return go(0, 0);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<(solve()?"YES":"NO")<<"\n";
    }    
    return 0;
}