#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 300005;
int a[MX];
int n;

void solve() {
    int c1 = n / 3;
    int c2 = c1;
    int d =  n - (c1 + 2 * c2);
    if (d == 2) ++c2;
    else if (d == 1) ++c1;
    cout << c1 << " " << c2 << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        solve();
    }
    
    return 0;
}