#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5;
int t, f[N];
long long n, k, a[N];

void Enter() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    long long res = 0;
    if (n <= k) {
        FOR(i, 1, n) res += a[i];
        res += n * (k - 1) - n * (n - 1) / 2;
    }
    else {
        FOR(i, 1, n) {
            a[i] += a[i - 1];
            if (i >= k) res = max(res, a[i] - a[i - k]);
        }
        res += k * (k - 1) / 2;
    }
    cout << res << '\n';
}

int main()
{
    #define file ""
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}