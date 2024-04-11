#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, a[N], dp[N], ok[N], res;

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int x;
    cin >> x;
    FOR(i, 1, n) a[i] -= x;
}

void Process() {
    dp[1] = 1; ok[1] = 0;
    FOR(i, 2, n) {
        if (dp[i-1] > dp[i-2] && a[i] + a[i-1] >= 0 && (!ok[i-1] || a[i] + a[i-1] + a[i-2] >= 0)) {
            dp[i] = dp[i-1] + 1;
            ok[i] = 1;
        }
        else {
            dp[i] = dp[i-2] + 1;
            ok[i] = 0;
        }
    }
    cout << dp[n] << '\n';
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