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
int n, L, R;

LL solve() {
    LL res = 0;
    sort(a, a+n);
    REP(i, n) {
        int l = lower_bound(a, a+n, L - a[i]) - a;
        int r = upper_bound(a, a+n, R - a[i]) - a;
        if (l >= r) continue;
        res += r - l - (l <= i && i < r);
    }
    return res >> 1; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>L>>R;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}