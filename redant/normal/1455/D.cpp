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

const int INF = 10006;
const int MX = 502;
int a[MX];
int n, x, k;
bool v[MX][MX][MX];
short m[MX][MX][MX];

short f(int i, int pr, int x) {
    if (i > n) return 0;
    short &r = m[i][pr][x];
    if(v[i][pr][x]) return r;
    v[i][pr][x] = true;
    r = INF;
    if (a[i] >= pr)
        r = min(r, f(i+1, a[i], x));
    if (x < a[i] && x >= pr) {
        short rr = 1 + f(i+1, x, a[i]);
        if (rr < r) r = rr;
    }
    return r;
}

int solve() {
    int mx = x;
    REP(i, n) mx = max(mx, a[i+1]);
    REP(i, n+1) REP(j, mx+1) REP(k, mx+1)
        v[i][j][k] = false;
    int r = f(1, 0, x);
    return r >= INF ? -1 : r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>x;
        REP(i, n) {
            cin>>a[i+1];
        }
        ++k;
        cout<<solve()<<"\n";
    }
    
    return 0;
}