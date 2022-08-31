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

const int MX = 100005;
string s;
int n, p, k;
int x, y;
int a[MX];

void pr() {
    REP(i, k) cout << a[i] << " ";
    cout << endl;
}

LL solve() {
    REP(i, k) a[i] = 0;
    FOR(i, p-1, n) a[i%k] += (1 - (s[i]-'0'));
    LL yy = 0, xx = x;
    LL r = 1e18;
    for (int i = 0, j = p - 1; j < n; i++, j++) {
        // cout << i << " : "; pr();
        r = min(r, yy + a[j%k] * xx);
        // cout << "r = " << r << ", cost = " << (yy + a[j%k] * xx) << endl;
        yy += y;
        a[j%k] -= (1 - (s[j]-'0'));
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>p>>k>>s>>x>>y;
        cout<<solve()<<"\n";
    }
    
    return 0;
}