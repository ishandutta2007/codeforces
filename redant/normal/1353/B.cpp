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

const int MX = 111;
int a[MX], b[MX];
int n, k;

int solve() {
    sort(a, a+n);
    sort(b, b+n);
    REP(i, k) {
        a[i] = max(a[i], b[n-1-i]);
    }
    int r = 0;
    REP(i, n) r += a[i];
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n) {
            cin>>a[i];
        }
        REP(i, n) {
            cin>>b[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}