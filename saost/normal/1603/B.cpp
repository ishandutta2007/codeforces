#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
#define pii pair<long long,int>
using namespace std;
const int N = 100005;
long long t, n, m, k, res, a[N], f[N];

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (m >= n) cout << m - m%n/2 << '\n';
        else cout << n * m + m << '\n';
    }
}