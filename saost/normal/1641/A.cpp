#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5;
long long t, n, x, res, a[N], ans[N];

void Enter() {
    cin >> n >> x;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    sort(a+1, a+n+1);
    int j = 1;
    FOR(i, 1, n) ans[i] = 0;
    FOR(i, 1, n) {
        if (ans[i]) continue;
        j = max(j, i + 1);
        while (j <= n && a[j] < a[i] * x) ++j;
        if (j<=n && a[i] * x == a[j]) {
            ans[i] = ans[j++] = 1;
        }
    }
    res = 0;
    FOR(i, 1, n) res += (ans[i] == 0);
    cout << res << '\n';
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