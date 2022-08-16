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

const int MX = 1005;
int a[MX], b[MX];
int n;

inline int dist(int i, int j) {
    return abs(a[i] - a[j]) + abs(b[i] - b[j]);
}

int solve() {
    int r = 0;
    LL mn = 2e15;
    REP(i, n) {
        LL c = 0;
        REP(j, n) c += dist(i, j);
        if (c < mn) mn = c, r = 1;
        else if (c == mn) ++r;
    }
    return r;
}

LL get(int *ar) {
    if (n&1) return 1;
    sort(ar, ar+n);
    return ar[n/2] - ar[n/2 - 1] + 1;
}

LL solve2() {
    return 1ll * get(a) * get(b);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i]>>b[i];
        }
        cout<<solve2()<<"\n";
    }
    
    return 0;
}