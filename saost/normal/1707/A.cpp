#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, q, k, res;
int a[N], ans[N], f[N];

void Enter() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    int tmp = 0;
    FORD(i, n, 1) {
        if (tmp < a[i] && tmp < q) ++tmp, ans[i] = 1;
        else if (tmp >= a[i]) ans[i] = 1;
        else ans[i] = 0;
    }
    FOR(i, 1, n) cout << ans[i];
    cout << '\n';
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