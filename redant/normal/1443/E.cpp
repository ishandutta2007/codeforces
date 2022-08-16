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
int a[MX];
LL sum[MX];
LL fac[16];
int n, st;
LL m = 0;

void perm(int l, int r, LL m) {
    if (m <= 0) return;

    if (fac[0] == 0) {
        fac[0] = 1;
        REP(i, 14) fac[i+1] = fac[i] * (i+1);
    }
    
    // cout << "m = " << m << endl;
    for (int i = l; i <= r; i++) {
        int k = r - i;
        int pos = i  + (m / fac[k]);
        m %= fac[k];
        int t = a[pos];
        for (int j = pos - 1; j >= i; j--)
            a[j + 1] = a[j];
        a[i] = t;
    }
}

LL solve(int l, int r) {
   LL res = 0;
   if (r >= st) {
        FOR(i, st, n+1)
            a[i] = i;
        perm(st, n, m);
        // FOR(i, st, n+1) cout << a[i] << ", ";
        // cout<<endl<<endl;
        FOR(i, st, n+1)
            sum[i] = sum[i-1] + a[i];
   }
   return sum[r] - sum[l-1];
}

int main() {
    setIO();
    cin >> n;
    st = max(1, n - 14);
    sum[0] = 0;
    a[0] = 0;
    REP(i, n) {
        a[i+1] = i + 1;
        sum[i+1] = sum[i] + i + 1;
    }
    int t; cin>>t;
    while(t--) {
        int op; cin>>op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            cout << solve(x, y) << endl;
        } else {
            int x; cin >> x;
            m += x;
        }
    }
    
    return 0;
}