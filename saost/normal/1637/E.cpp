#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const long long N = 3e5 + 5, INF = 0x3c3c3c3c3c;
int t, n, m, sz, a[N], id[N];
long long res;
map<long long, bool> M;
vector<int> Q[N];

void Enter() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        M[u * INF + v] = 1;
    }
}

bool good(int u, int v) {
    if (u > v) swap(u, v);
    return !M.count(u * INF + v);
}

bool update(int u, int v, int cc) {
    if (u == v || !good(u, v)) return false;
    res = max(res, (long long) (u + v) * cc);
    return true;
}

void Process() {
    sort(a+1, a+n+1);
    FORD(i, n, 1) {
        int j = i;
        while (i && a[i] == a[j]) --i;
        Q[j - i].push_back(a[j]);
        ++i;
    }

    FOR(i, 1, n) if (Q[i].size()) id[++sz] = i;
    FOR(i, 1, sz) {
        int ci = id[i];
        FOR(j, 1, i) {
            int cj = id[j];
            int w = 0;
            while (w < Q[ci].size()) {
                int v0 = Q[ci][w];
                if (update(v0, Q[cj][0], ci + cj)) break;
                for(int v : Q[cj]) if (update(v0, v, ci + cj))
                    break;
                ++w;
            }
        }
    }
    cout << res << '\n';
}

void Reset() {
    res = sz = 0;
    M.clear();
    FOR(i, 1, n) {
        Q[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
        Reset();
    }
}