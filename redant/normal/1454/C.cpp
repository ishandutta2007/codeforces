#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int a[MX];
vector<int> pos[MX];
int n;

int solve() {
    REP(i, n) {
        pos[i].clear();
        pos[i].push_back(-1);
    }
    REP(i, n)
        pos[a[i]].push_back(i);
    REP(i, n)
        pos[i].push_back(n);
    int r = n;
    REP(i, n) {
        int m = pos[i].size();
        if (m == 2) continue;
        int c = 0;
        REP(j, m-1) {
            c += pos[i][j+1] - pos[i][j] > 1;
        }
        r = min(r, c);
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
            --a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}