#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
const int K = 18;
int a[MX];
int lg[MX];
int g[2*MX][K+1];
int n, k;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void init() {
    lg[1] = 0;
    for (int i = 2; i < MX; i++)
        lg[i] = lg[i>>1] + 1;
}

int f(int l, int r) {
    int j = lg[r-l+1];
    return gcd(g[l][j], g[r-(1<<j)+1][j]);
}

int ok(int m, int exp) {
    REP(i, n)
        if (f(i, i + m - 1) != exp) {
            // cout << "m = " << m << " failed for i = " << i << ", result = " << f(i, i + m - 1) << "\n";
            return 0;
        }
    // cout << "m = " << m << " works!" << "\n";
    return 1;
}

int solve() {
    // pre-compute
    REP(i, n)
        g[i][0] = g[n+i][0] = a[i];
    k = lg[n];
    // cout << "n = " << n << ", k = " << k << "\n";
    for (int j = 1; j <= k; j++) {
        // cout << "j = " << j << " : ";
        for (int i = 0; i + (1 << j) <= 2 * n; i++) {
            g[i][j] = gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
            // cout << g[i][j] << " ";
        }
        // cout << "\n";
    }

    int tg = f(0, n-1);
    // cout << "tg = " << tg << endl;
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (ok(m, tg))
            r = m;
        else
            l = m + 1;
    }
    return l - 1;
}

int main() {
    setIO();
    int t; cin>>t;
    init();
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}