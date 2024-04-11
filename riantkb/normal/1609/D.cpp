#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;


struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};


const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    T = 1;
    // cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, m;
        cin >> n >> m;
        dsu uf(n);
        int c = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            if (uf.same(u, v)) {
                ++c;
            }
            else {
                uf.merge(u, v);
            }
            vector<int> sizes;
            for (int j = 0; j < n; ++j) {
                if (uf.leader(j) == j) {
                    sizes.push_back(uf.size(j));
                }
            }
            sort(sizes.begin(), sizes.end());
            reverse(sizes.begin(), sizes.end());
            int ans = 0;
            for (int i = 0; i < c + 1 && i < (int)sizes.size(); ++i) {
                ans += sizes[i];
            }
            cout << ans - 1 << '\n';
        }

    }
    return 0;
}