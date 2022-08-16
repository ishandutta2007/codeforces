#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const LL mod = 998244353;

const int MX = 200005;
int x[MX], y[MX], s[MX];
LL t[MX], tsum[MX];
int n;

int solve() {
    REP(i, n) {
        int j = lower_bound(x, x + n, y[i]) - x;
        t[i] = (x[i] - y[i] + tsum[i] - tsum[j] + mod) % mod;
        tsum[i + 1] = (tsum[i] + t[i]) % mod;
    }
    LL r = (x[n - 1] + 1) % mod;
    REP(i, n)
        if (s[i]) {
            r += t[i];
            if (r >= mod)
                r %= mod;
        }
    return r;
}

int main() {
    setIO();
    int t=1; // cin>>t;
    while(t--) {
        cin >> n;
        REP(i, n) {
            cin >> x[i] >> y[i] >> s[i];
        }
        cout<<solve()<<"\n";
    }
    return 0;
}