#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
using namespace std;
int t, n, l[100005], r[100005], avail[100005];
long long f1[100005], f2[100005];
vector<int> S[100005];

void visit(int u) {
    avail[u] = true;
    for(int v : S[u]) if (!avail[v]) {
        visit(v);
        f1[u] += max(f2[v] + abs(r[v] - l[u]), f1[v] + abs(l[v] - l[u]));
        f2[u] += max(f1[v] + abs(l[v] - r[u]), f2[v] + abs(r[v] - r[u]));
    }
}

void Solve() {
    visit(1);
    cout << max(f1[1], f2[1]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        int u, v;
        for(int i=1; i<=n; ++i) cin >> l[i] >> r[i], S[i].clear(), avail[i] = false, f1[i] = f2[i] = 0;
        for(int i=1; i<n; ++i) {
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        Solve();
    }
}