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

const int mod = (int) 1e9 + 7;

void mfix(int &a) {
    while (a < 0) a += mod;
    while (a >= mod) a -= mod;
}

int madd(int a, int b) {
    a = a + b;
    mfix(a);
    return a;
}

int mmul(int a, int b) {
    mfix(a);
    mfix(b);
    return (a * 1ll * b) % mod;
}

const int MX = 5002;
int a[MX];
int n, k, q;
int cnt[MX][MX];
int dp[MX];

int main() {
    setIO();
    cin>>n>>k>>q;
    REP(i, n) cin >> a[i+1];
    REP(i, n) cnt[i+1][0] = 1;
    REP(j, k) {
        REP(i, n) {
            cnt[i+1][j+1] = madd(cnt[i][j], cnt[i+2][j]);
        }
    }

    REP(i, n) {
        REP(j, k+1) {
            dp[i+1] = madd(dp[i+1], mmul(cnt[i+1][j], cnt[i+1][k-j]));
        }
    }

    int r = 0;
    REP(i, n) {
        r = madd(r, mmul(dp[i+1], a[i+1]));
    }

    while (q--) {
        int i, v;
        cin>>i>>v;
        r = madd(r, mmul(dp[i], v - a[i]));
        a[i] = v;
        cout << r << "\n";
    }
    return 0;
}