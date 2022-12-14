#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=1; i<=r; ++i)
#define REP(i,l,r) for(int i=1; i<r; ++i)
using namespace std;
const int N = 55;
long long n, mod, sl[N][N*N], tcd[N][N*N], f[N];

void Enter() {
}

void Process() {
}

int main()
{
    cin >> n >> mod;
    sl[0][0] = 1;
    for(int i=0; i<=n*(n-1)/2; ++i) tcd[0][i] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=n*(n-1)/2; ++j) {
            sl[i][j] = tcd[i-1][j];
            if (j >= i)
                sl[i][j] = (sl[i][j] - tcd[i-1][j-i] + mod) % mod;
        }
        tcd[i][0] = sl[i][0];
        for(int j=1; j<=n*(n-1)/2; ++j) tcd[i][j] = (tcd[i][j-1] + sl[i][j]) % mod;
    }

    for(int i=1; i<=n; ++i) {
        f[i] = f[i-1] * i % mod;
        for(int j1=1; j1<=i; ++j1)
        for(int j2=j1+1; j2<=i; ++j2) {
            for(int w1=0; w1<=(i-1)*(i-2)/2; ++w1)
                if (w1 - (j2-j1+1) >= 0)
                    f[i] = (f[i] + sl[i-1][w1] * tcd[i-1][w1 - (j2-j1+1)] % mod) % mod;
        }
    }
    cout << f[n];
}