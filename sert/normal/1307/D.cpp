#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

const int INF = (int)1e9 + 41;

vector<int> bfs(int st, const vector<vector<int>> &es) {
    int n = es.size();
    vector<int> d(n, INF);
    d[st] = 0;
    queue<int> q;
    q.push(st);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : es[v]) {
            if (d[w] == INF) {
                d[w] = d[v] + 1;
                q.push(w);
            }
        }
    }
    return d;
}

struct K {
    int first, second, i;
};

bool cmp(const K &a, const K &b) {
    return a.second - a.first < b.second - b.first;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> es(n);
    vector<bool> u(n, false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        u[x - 1] = true;
    }
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    auto d1 = bfs(0, es);
    auto dn = bfs(n - 1, es);
    
    vector<K> a(n);
    for (int i = 0; i < n; i++) a[i] = {d1[i], dn[i], i};
    sort(a.begin(), a.end(), cmp);

    //for (int i = 0; i < n; i++) cout << d1[i] << " ";
   // cout << "\n";
    //for (int i = 0; i < n; i++) cout << dn[i] << " ";
    //cout << "\n";

    int mx = -INF;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!u[a[i].i]) continue;     
        //cout << a[i].i + 1 << endl;   
        if (mx != -INF)
            ans = max(ans, a[i].second + mx + 1);
        mx = max(mx, a[i].first);
    }

    cout << min(ans, dn[0]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}