#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    int num;
    vector<int> par, sz, rank;
    UnionFind(int n) : num(n) {
        par = vector<int>(n);
        sz = vector<int>(n, 1);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) par[i] = i;
    }
private:
    int find(int x) {
        return par[x] == x ? x : (par[x] = find(par[x]));
    }
public:
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        --num;
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        }
        else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) ++rank[x];
        }
        return true;
    }
    bool ispar(int x) {
        return x == find(x);
    }
    int getpar(int x) {
        return find(x);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, pair<int, int>>> tmp(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        tmp[i] = make_pair((long long)c * 2, make_pair(u, v));
    }
    long long ok = 0, ng = 2000000000;
    while (ok + 1 < ng) {
        long long mid = (ok + ng) / 2;
        vector<pair<long long, pair<int, int>>> edges(m);
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
                edges[i] = make_pair(mid, tmp[i].second);
            else {
                edges[i] = tmp[i];
            }
        }
        UnionFind uf(n);
        sort(edges.begin(), edges.end());
        for (auto& item : edges)
        {
            if (uf.unite(item.second.first, item.second.second))  {
                if (item.second.first == tmp[0].second.first && item.second.second == tmp[0].second.second) {
                    ok = mid;
                    goto A;
                }
            }
            if (uf.same(tmp[0].second.first, tmp[0].second.second)) {
                break;
            }
        }
        ng = mid;
        A: continue;
    }
    cout << ((ok + 1) / 2) << '\n';
    return 0;
}