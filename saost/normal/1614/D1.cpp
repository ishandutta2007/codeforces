#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 5000001;
int n, x, cnt[N], p[N];
long long f[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    FOR(i, 1, n) cin >> x, ++cnt[x];
    int dem = 0;
    REPD(i, N, 1) {
        for(int j=i; j<N; j+=i) p[i] += cnt[j];
        f[i] = 1LL * p[i] * i;
        for(int j=i*2; j<N; j+=i) f[i] = max(f[i], f[j] + 1LL * (p[i] - p[j]) * i);
    }
    cout << f[1];
}