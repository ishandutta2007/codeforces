#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int mod = 1000000007;
int n;

int madd(int a, int b) {
    a = a + b;
    while (a < 0) a += mod;
    while (a >= mod) a -= mod;
    return a;
}

int mmul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int mpow(int a, int n) {
    int r = 1;
    for(; n; n >>= 1) {
        if (n&1) r = mmul(r, a);
        a = mmul(a, a);
    }
    return r;
}

int fac(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f = mmul(i, f);
    }
    return f;
}

int solve() {
    return madd(fac(n), mod - mpow(2, n-1));
}

int main() {
    setIO();
    cin>>n;
    cout<<solve()<<"\n";   
    return 0;
}