#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 500005;
const int INF = 0x3c3c3c3c;
int t, n, cnt;
long long a[N];
int bit[N], bit2[N], avail[N], ans[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i], a[i] += a[i - 1];
}

void Compress() {
    vector<long long> Q;
    FOR(i, 0, n) Q.push_back(a[i]);
    sort(Q.begin(), Q.end());
    Q.resize(unique(Q.begin(), Q.end()) - Q.begin());
    FOR(i, 0, n) a[i] = lower_bound(Q.begin(), Q.end(), a[i]) - Q.begin() + 1;
    cnt = Q.size();
}

void update(int x, int val) {
    for(++x; x <= cnt; x += x & -x)
        bit[x] = max(bit[x], val);
}

void update2(int x, int val) {
    for(--x; x; x -= x & -x)
        bit2[x] = max(bit2[x], val);
}

int query(int x) {
    int val = -INF;
    for(; x; x -= x & -x)
        val = max(val, bit[x]);
    return val;
}

int query2(int x) {
    int val = -INF;
    for(; x <= cnt; x += x & -x)
        val = max(val, bit2[x]);
    return val;
}

void Process() {
    fill(bit + 1, bit + cnt + 1, -INF);
    fill(bit2 + 1, bit2 + cnt + 1, -INF);
    fill(avail + 1, avail + cnt + 1, -INF);
    FOR(i, 1, n) {
        update(a[i - 1], ans[i - 1] - (i - 1));
        update2(a[i - 1], ans[i - 1] + (i - 1));
        avail[a[i - 1]] = max(avail[a[i - 1]], ans[i - 1]);
        ans[i] = max({avail[a[i]], query(a[i]) + i, query2(a[i]) - i});
    }
    cout << ans[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Compress();
        Process();
    }
}