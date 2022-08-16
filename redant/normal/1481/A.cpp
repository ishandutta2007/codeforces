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

int px, py;
string s;

int check(int p, int d[]) {
    if (p < 0) return -p <= d[0];
    return p <= d[1];
}

int solve() {
    int dx[2] = {0};
    int dy[2] = {0};
    for (char c : s) {
        if (c == 'U') dy[1]++;
        if (c == 'D') dy[0]++;
        if (c == 'L') dx[0]++;
        if (c == 'R') dx[1]++;
    }
    return check(px, dx) && check(py, dy);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>px>>py>>s;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}