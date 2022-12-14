#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m;
int a[N], b[N], f[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    long long res = 0, k = 0, store = 0, c_1 = 0;
    FOR(i, 2, n - 1) {
        res += (a[i] + 1) / 2;
        if (a[i] % 2 == 0 && a[i]) k = 2;
        if (a[i] == 1) ++c_1;
        if (a[i] > 1) ++k;
    }
    if (k > 1 || k && c_1) cout << res << '\n';
    else cout << -1 << '\n';
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