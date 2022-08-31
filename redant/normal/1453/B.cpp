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

const int MX = 200005;
LL a[MX];
int n;

LL f(int i, LL v) {
    assert(1 <= i && i <= n);
    if (i == 1) return abs(v - a[i+1]);
    if (i == n) return abs(v - a[i-1]);
    return abs(v - a[i-1]) + abs(v - a[i+1]);
}

LL g() {
    LL r = 0;
    for (int i = 1; i < n; i++)
        r += abs(a[i] - a[i+1]);
    return r;
}

LL h(int i, LL v) {
    LL t = a[i];
    a[i] = v;
    LL r = g();
    a[i] = t;
    return r;
}

LL solve() {
    LL mx = 0, mxv = 0, mxi = 0;
    REP(i, n) {
        LL c1 = f(i+1, a[i+1]);
        for (int j = -1; j < 2; j++) {
            LL cv = a[i+1+j];
            LL c2 = f(i+1, cv);
            if (c1 - c2 > mx) {
                mx = c1 - c2;
                mxv = cv;
                mxi = i+1;
            }
        }
    }

    LL r = g();
    if (mx > 0) {
        r = min(r, h(mxi, mxv));
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i+1];
        }
        a[n+1] = 0;
        cout<<solve()<<"\n";
    }
    
    return 0;
}