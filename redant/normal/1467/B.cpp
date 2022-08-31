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
int a[MX];
int n;

bool is(int i) {
    if (i > 0 && i + 1 < n) {
        return (a[i-1] < a[i] && a[i] > a[i+1]) || (a[i-1] > a[i] && a[i] < a[i+1]);
    }
    return false;
}

int check(int i, int v) {
    int prv = is(i-1) + is(i) + is(i+1);
    int t = a[i];
    a[i] = v;
    int nxt = is(i-1) + is(i) + is(i+1);
    a[i] = t;
    return prv - nxt;
}

int solve() {
    int r = 0;
    REP(i, n) r += is(i);
    int mx = 0;
    REP(i, n) {
        if (i) mx = max(mx, check(i, a[i-1]));
        if (i+1<n) mx = max(mx, check(i, a[i+1]));
    }
    return r - mx; 
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