#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 300005;
int t, n, timer, ans, L[N], R[N];
vector<int> S1[N], S2[N];
set<pii> Q;

void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) S1[i].clear(), S2[i].clear();
    int x;
    for(int i=2; i<=n; ++i) {
        cin >> x;
        S1[x].push_back(i);
    }
    for(int i=2; i<=n; ++i) {
        cin >> x;
        S2[x].push_back(i);
    }
}

void DFS1(int u) {
    L[u] = ++timer;
    for(int v : S2[u]) DFS1(v);
    R[u] = timer;
}

int get(int x) {
    set<pii>::iterator it = Q.lower_bound({L[x], x});
    if (it != Q.end() && R[it->second] <= R[x]) return -2;
    if (it == Q.begin()) return -1;
    --it;
    int res = it->second;
    if (R[res] < R[x]) return -1;
    Q.erase({L[res], res});
    return res;
}

void DFS2(int u) {
    int ok = get(u);
    if (ok != -2) Q.insert({L[u], u});
    ans = max(ans, (int)Q.size());
    for(int v : S1[u]) DFS2(v);
    if (ok != -2) {
        Q.erase({L[u], u});
        if (ok != -1) Q.insert({L[ok], ok});
    }
}

void Process() {
    timer = ans = 0;
    DFS1(1);
    DFS2(1);
    cout << ans << '\n';
    if (!Q.empty()) cout << -1;
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