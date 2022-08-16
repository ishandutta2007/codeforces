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
int a[MX];
int n;

LL solve() {
    LL sum = 0;
    int mx = 0;
    REP(i, n) {
        sum += a[i];
        mx = max(mx, a[i]);
    }
    return max(1ll * mx * (n-1) - sum, (1ll * n - 1 - (sum % (n - 1))) % (n - 1));
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}