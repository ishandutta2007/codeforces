#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005, MOD = 1e9 + 7;
int t, n, q, k, res;
int a[N], ans[N];
long long f[N], f2[N], f3[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    int ii = 0;
    while (n > 1) {
        sort(a + ii + 1, a + n + 1);
        while (ii < n && a[ii + 1] == 0) ++ii;
        if (ii) --ii;
        int n2 = n; n = ii;
        REP(i, ii + 1, n2) a[++n] = a[i + 1] - a[i];
    }
    cout << a[1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}