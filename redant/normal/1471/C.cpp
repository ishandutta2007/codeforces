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

const int MX = 300005;
int a[MX], c[MX];
int n, m;

LL solve() {
    LL r = 0;
    sort(a, a+n);
    REP(i, n) {
        int k = a[n-1-i];
        if (k <= i) {
            REP(j, n-i)
                r += c[a[j]];
            break;
        }
        r += c[i];
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i];
            --a[i];
        }
        REP(i, m) {
            cin>>c[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}