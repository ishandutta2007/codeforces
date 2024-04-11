#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int mcs = 1e9, Mcs = 1;
const int MAXN = 1e5 + 10;
int rep[MAXN], sz[MAXN], cc, isol;
multiset<int> cs;

int find(int u) {
    return (rep[u] == -1 ? u : rep[u] = find(rep[u]));
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    rep[v] = u;
    if(sz[u] > 1)
        cs.erase(cs.find(sz[u]));
    if(sz[v] > 1)
        cs.erase(cs.find(sz[v]));
    sz[u] += sz[v];
    cs.insert(sz[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ii> ps;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ps.push_back({x, i + 1});
    }
    memset(rep, -1, sizeof rep);
    fill(sz, sz + MAXN, 1);
    sort(ps.begin(), ps.end());
    vector<ii> anss;
    for(auto &p : ps) {
        int position = p.second;
        join(position - 1, position);
        if(cs.size() && *(cs.begin()) == *(prev(cs.end()))) {
            anss.push_back({-cs.size(), p.first});
        }
    }

    sort(anss.begin(), anss.end());
    cout << anss[0].second + 1 << '\n';
}