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

const int MX = 105;
LL x[MX], y[MX];
int n;
LL k;

// inline LL sq(LL x) { return x * x; }

int solve() {
    REP(i, n) {
        int count = 0;
        REP(j, n) {
            count += (abs(x[i]-x[j]) + abs(y[i]-y[j])) <= k;
        }
        if (count == n)
            return 1;
    }
    return -1;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n) {
            cin>>x[i]>>y[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}