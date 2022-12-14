#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 20000001;
int n, x, cnt, p[N], d[N], prime[N], Q[20], c[20];
long long f[N];

void eratos() {
    for(int i=2; i<N; ++i) {
        if (!d[i]) d[i] = prime[++cnt] = i;
        for(int j = 1; j <= cnt && prime[j] <= d[i] && prime[j] * i < N; ++j)
            d[prime[j] * i] = prime[j];
    }
}

void Add(int pos, int r, int x) {
    if (pos > r) return (void) (++p[x]);
    FOR(i, 0, c[pos]) {
        Add(pos + 1, r, x);
        if (i != c[pos]) x *= Q[pos];
    }
}

void Build(int x) {
    int r = 0;
    for(; x != 1; x /= d[x]) {
        if (Q[r] != d[x]) Q[++r] = d[x], c[r] = 0;
        ++c[r];
    }
    Add(1, r, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    eratos();
    cin >> n;
    FOR(i, 1, n) {
        cin >> x;
        Build(x);
    }
    REPD(i, N, 1) if (p[i]) {
        f[i] = 1LL * p[i] * i;
        for(int j = 1; j <= cnt && prime[j] * i < N; ++j)
            f[i] = max(f[i], f[prime[j] * i] + 1LL * (p[i] - p[prime[j] * i]) * i);
    }
    cout << f[1];
}