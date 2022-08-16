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

const int MX = 55;
LL a[MX];
int n;

void solve() {
    LL sum[2] = {0};
    REP(i, n) sum[i%2] += a[i];
    int k = sum[0] > sum[1];
    FOR(i, k, n) a[i++] = 1;
    REP(i, n) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        solve();
    }
    
    return 0;
}