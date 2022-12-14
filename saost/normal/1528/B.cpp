#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
using namespace std;
int n;
long long g[1000005], f[1000005], sum[1000005];

void eratos() {
    for(long long i=2; i<=1000000; ++i) {
        for(long long j=i; j<=1000000; j+=i) ++f[j];
    }
    //for(int i=1; i<=10; ++i) cout << f[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    eratos();
    g[1] = sum[1] = 1;
    for(int i=2; i<=n; ++i) {
        g[i] = (sum[i-1] + f[i] + 1) % 998244353;
        sum[i] = (sum[i-1] + g[i]) % 998244353;
    }
    cout << g[n];
}