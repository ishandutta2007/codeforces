#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 15;
int nxt[MAXN];
vector<int> p, q;
map<pair<int, int>, set<int>> all;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> tri(n);
    for(int i = 1; i <= n - 2; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tri[i] = {a, b, c};
        if(i > 1) {
            all[{min(a, b), max(a, b)}].insert(i);
            all[{min(c, b), max(c, b)}].insert(i);
            all[{min(a, c), max(a, c)}].insert(i);
        }
    }
    auto t = tri[1];
    int vs = 3;
    nxt[t[0]] = t[1];
    nxt[t[1]] = t[2];
    nxt[t[2]] = t[0];
    q.push_back(1);
    int u = t[0], v = t[1];
    while(vs < n) {
        //if(u == v)
        //    exit(0);
        //cout << u << " " << v << " " << vs << endl;
        int uu = min(u, v), vv = max(u, v);
        if(all[{uu, vv}].empty()) {
            u = nxt[u];
            v = nxt[v];
            continue;
        }
        auto p = *all[{uu, vv}].begin();
        auto t = tri[p];
        q.push_back(p);
        int a = t[0], b = t[1], c = t[2];
        all[{min(a, b), max(a, b)}].erase(p);
        all[{min(c, b), max(c, b)}].erase(p);
        all[{min(a, c), max(a, c)}].erase(p);
        nxt[u] = a + b + c - u - v;
        nxt[a + b + c - u - v] = v;
        v = nxt[u];
        vs++;
    }
    int st = 1;
    for(int i = 1; i <= n; i++) {
        cout << st << " ";
        st = nxt[st];
    }
    cout << '\n';
    reverse(q.begin(), q.end());
    for(auto x : q)
        cout << x << " ";
    cout << '\n';
    q.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}