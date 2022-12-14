#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
int t, n, m, k, res, avail[N];
long long a[N], f[N];
map<long long, int> M, M2[N];
vector<int> S[N];

struct Data {
    long long x, y;
    bool operator < (Data &p) { return y < p.y; }
} b[N];

void Enter() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
        int x;
        cin >> x;
        a[i] -= x;
        a[i] += a[i - 1];
    }
    FOR(i, 1, k) cin >> b[i].x >> b[i].y;
}

void update(int x, long long num) {
    for(; x <= n; x += x&-x) M2[x][num] = 1;
}

bool query(int x, long long val) {
    for(; x; x -= x&-x) if (M2[x].count(val)) return true;
    return false;
}

void Process() {
    FOR(i, 0, n) S[i].clear(), avail[i] = 0;
    FOR(i, 1, k) {
        auto [x, y] = b[i];
        S[x - 1].push_back(y);
        S[y].push_back(x - 1);
    }
    vector<int> Q;
    set<int> SET;
    FOR(i, 0, n) {
        if (a[i] != 0) SET.insert(i);
        else Q.push_back(i), avail[i] = 1;
    }
    REP(i, 0, Q.size()) {
        int u = Q[i];
        for(int v : S[u]) if (avail[v]) {
            int mini = min(u, v);
            int maxi = max(u, v);
            while (true) {
                auto tmp = SET.lower_bound(mini);
                if (tmp != SET.end() && *tmp <= maxi) {
                    avail[*tmp] = 1;
                    Q.push_back(*tmp);
                    SET.erase(tmp);
                }
                else break;
            }
        }
    }
    cout << (SET.empty() ? "YES\n" : "NO\n");
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