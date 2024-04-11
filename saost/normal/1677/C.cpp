#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
int t, n, m, k, cnt;
int a[N], b[N], avail[N];
vector<int> S[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) {
        S[a[i]].push_back(b[i]);
        S[b[i]].push_back(a[i]);
    }
}

void DFS(int u) {
    ++cnt;
    avail[u] = 1;
    for(int v : S[u]) if (!avail[v])
        DFS(v);
}

void Process() {
    vector<int> Q;
    FOR(i, 1, n) if (!avail[i]) {
        cnt = 0;
        DFS(i);
        Q.push_back(cnt);
    }
    sort(Q.begin(), Q.end(), greater<int>());
    long long res = 0;
    int sz = n;
    for(int v : Q) {
        REP(i, 0, v / 2) {
            res += (sz - 1) * 2;
            sz -= 2;
        }
    }
    cout << res << '\n';

    fill(avail+1, avail+n+1, 0);
    FOR(i, 1, n) S[i].clear();
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