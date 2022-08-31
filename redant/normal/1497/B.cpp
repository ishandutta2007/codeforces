#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int f[MX];
int n, m;

int solve() {
    int r = f[0] > 0;
    int i = 1, j = m - 1;
    while (i < j) {
        if (!f[i] && !f[j]) {
            ++i; --j; continue;
        }
        int d = abs(f[i] - f[j]);
        ++r;
        if (d > 1) {
            ++r;
            r += d - 2;
        }
        ++i; --j;
    }
    if (i == j) r += f[i] > 0;
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, m) f[i] = 0;
        REP(i, n) {
            int x;
            cin>>x;
            x%=m;
            f[x]++;
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}