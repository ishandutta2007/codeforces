#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const long long N = 2e5 + 5, INF = 1e15;
int t, n, m, hs;
int ok0[N], ok1[N], ok2[N], prefix0[N], prefix1[N], prefix2[N];
int a[N], sz[N], age[N], ages[N], pos[N], ans[N];
long long sum[N];
int b[N], b_inv[N];

void Reset() {
    hs = 0;
    FOR(i, 1, m) sum[i] = 0;
}

void Enter() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        cin >> sz[i];
        FOR(j, 1, sz[i]) {
            int x;
            cin >> x;
            age[++hs] = x;
            pos[hs] = i;
            sum[i] += x;
        }
    }
}

void Process() {
    sort(a+1, a+n+1, greater<int>());
    FOR(i, 1, m) b[i] = i;
    sort(b+1, b+m+1, [] (int x, int y) { return (sum[x] + sz[x] - 1) / sz[x] > (sum[y] + sz[y] - 1) / sz[y]; });
    FOR(i, 1, m) b_inv[b[i]] = i;
    FOR(i, 1, m) ages[i] = (sum[b[i]] + sz[b[i]] - 1) / sz[b[i]];
    FOR(i, 1, m + 1) {
        ok0[i] = (a[i] >= ages[i]);
        ok1[i] = (a[i] >= ages[i + 1]);
        ok2[i] = (a[i] >= ages[i - 1]);
    }
    FOR(i, 1, m + 1) {
        prefix0[i] = prefix0[i - 1] + ok0[i];
        prefix1[i] = prefix1[i - 1] + ok1[i];
        prefix2[i] = prefix2[i - 1] + ok2[i];
    }

    FOR(i, 1, hs) {
        int id = pos[i];
        int gr = b_inv[id];
        int avr_age = (sum[id] - age[i] + sz[id] - 2) / (sz[id] - 1);
        int p = lower_bound(ages + 1, ages + m + 1, avr_age, greater<int>()) - ages;

        if (gr < p) {
            if (prefix0[gr - 1] == gr - 1 &&
                (p - 2 >= gr - 1 || prefix1[p - 2] - prefix1[gr - 1] == (p - 2) - (gr - 1)) &&
                a[p - 1] >= avr_age &&
                prefix0[m] - prefix0[p - 1] == m - (p - 1)
            )
                ans[i] = 1;
                else ans[i] = 0;
        }
        else if (gr >= p) {
            if (prefix0[p - 1] == p - 1 &&
                prefix2[gr] - prefix2[p] == gr - p &&
                a[p] >= avr_age &&
                prefix0[m] - prefix0[gr] == m - gr
            )
                ans[i] = 1;
                else ans[i] = 0;
        }
    }
    FOR(i, 1, hs) cout << ans[i];
    cout << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Reset();
        Enter();
        Process();
    }
}