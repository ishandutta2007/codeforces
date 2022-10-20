#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


class UnionFind {
private:
    int num;
    vector<int> par, sz, rank;
    int find(int x) {
        return par[x] == x ? x : (par[x] = find(par[x]));
    }
public:
    UnionFind(int n) {
        num = n;
        par = vector<int>(n);
        sz = vector<int>(n, 1);
        rank = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int unionsize(int x) {
        return sz[find(x)];
    }
    int unioncount() {
        return num;
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
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
};

int dd[] = { 0, 1, 0, -1 };

inline bool inside(int i, int j, int h, int w) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<P>> lis(h * w);
    vector<pair<int, P>> que(q);
    for (int i = 0; i < q; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        que[i] = { c, { x, y } };
        lis[x * w + y].push_back({ i, c });
    }
    vector<int> idx(h * w), ims(q);
    ims[0] = 1;

    for (int i = 0; i < q; ) {
        int r = i;
        while (r < q && que[r].first == que[i].first) ++r;

        int m = r - i;
        UnionFind uf(m);
        unordered_map<int, int> dic;
        vector<P> del;
        for (int j = i; j < r; ++j) {
            const P& p = que[j].second;
            int pp = p.first * w + p.second;
            if (dic.count(pp)) {
                continue;
            }
            int c = 1;
            for (int k = 0; k < 4; ++k) {
                int ti = p.first + dd[k], tj = p.second + dd[k ^ 1];
                if (inside(ti, tj, h, w) && dic.count(ti * w + tj)) {
                    if (uf.unite(j - i, dic[ti * w + tj] - i)) {
                        --c;
                    }
                }
            }
            dic[pp] = j;
            ims[j] += c;

            while (idx[pp] < (int)lis[pp].size() && lis[pp][idx[pp]].second == que[i].first) ++idx[pp];

            if (idx[pp] < (int)lis[pp].size()) {
                del.push_back({ lis[pp][idx[pp]].first, j });
            }
            else {
                del.push_back({ M, j });
            }
        }
        sort(del.begin(), del.end());
        reverse(del.begin(), del.end());

        uf = UnionFind(m);
        dic = unordered_map<int, int>();

        for (auto& iitem : del) {
            int j = iitem.second;

            const P& p = que[j].second;
            int pp = p.first * w + p.second;

            int c = 1;
            for (int k = 0; k < 4; ++k) {
                int ti = p.first + dd[k], tj = p.second + dd[k ^ 1];
                if (inside(ti, tj, h, w) && dic.count(ti * w + tj)) {
                    if (uf.unite(j - i, dic[ti * w + tj] - i)) {
                        --c;
                    }
                }
            }
            dic[pp] = j;

            if (iitem.first != M) {
                ims[iitem.first] += -c;
            }

        }

        i = r;
    }

    {
        int m = h * w;
        vector<P> del(h * w);
        for (int j = 0; j < h * w; ++j) {
            if (lis[j].size()) {
                del[j] = { lis[j][0].first, j };
            }
            else {
                del[j] = { M, j };
            }
        }
        sort(del.begin(), del.end());
        reverse(del.begin(), del.end());
        UnionFind uf(m);
        vector<bool> exi(m, false);

        for (auto& iitem : del) {
            int pp = iitem.second;
            P p = { pp / w, pp % w };

            int c = 1;
            for (int k = 0; k < 4; ++k) {
                int ti = p.first + dd[k], tj = p.second + dd[k ^ 1];
                if (inside(ti, tj, h, w) && exi[ti * w + tj]) {
                    if (uf.unite(pp, ti * w + tj)) {
                        --c;
                    }
                }
            }
            exi[pp] = true;

            if (iitem.first != M) {
                ims[iitem.first] += -c;
            }
        }

    }

    for (int i = 0; i < q; ++i) {
        if (i > 0) {
            ims[i] += ims[i - 1];
        }
        cout << ims[i] << '\n';
    }


    return 0;
}