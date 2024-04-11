#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, a[N], b[N], bit[N], p[26];
long long res;
string sa, sb;
vector<int> S[26];

void Enter() {
    cin >> n >> sa >> sb;
}

bool check() {
    REP(i, 0, n) if (sa[b[i]] != sb[i]) return sa[b[i]] < sb[i];
    return false;
}

void update(int x, int val) {
    for(++x; x; x-=x&-x) bit[x] += val;
}

int query(int x) {
    int val = 0;
    for(++x; x<=n; x+=x&-x) val += bit[x];
    return val;
}

void solve(int x, long long sum) {
    if (x == n || sum >= res) return;
    int w = sb[x] - 'a', val = 8e8;
    REP(i, 0, w) if (p[i] < S[i].size()) val = min(val, S[i][p[i]]);
    if (val != 8e8) {
        res = min(res, sum + val - x + query(val));
    }
    if (p[w] < S[w].size()) {
        int id = S[w][p[w]];
        long long tmp2 = id - x + query(id);
        update(id, 1);
        ++p[w];
        solve(x + 1, sum + tmp2);
        update(id, -1);
        --p[w];
    }
}

void Process() {
    REP(i, 0, n) b[i] = i;
    sort(b, b+n, [] (int x, int y) { return sa[x] < sa[y]; });
    int id = check();
    if (!id) {
        cout << -1 << '\n';
        return;
    }
    REP(i, 0, 26) S[i].clear(), p[i] = 0;
    REP(i, 0, n) S[sa[i] - 'a'].push_back(i);
    res = 1e10;
    solve(0, 0);
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