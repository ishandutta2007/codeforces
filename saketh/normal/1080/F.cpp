#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

struct seg_tree {
    using node = vector<array<int, 2>>;

    int S;
    vector<node> tree;
    seg_tree(vector<node>& leaves) : S(leaves.size()) {
        tree.resize(2 * S + 1);
        for (int i = 0; i < leaves.size(); i++)
            make_leaf(tree[i+S], leaves[i]);
        for (int i = S - 1; i > 0; i--)
            merge(tree[i], tree[2 * i], tree[2 * i + 1]);
    }

    void make_leaf(node& t, node& s) {
        sort(all(s));
        node c;
        for (auto [l, r] : s) {
            while (!c.empty() && c.back()[1] >= r)
                c.pop_back();
            c.push_back({ l, r });
        }

        int p = -1;
        for (auto [l, r] : c) {
            t.push_back({ p+1, r });
            p = l;
        }
        t.push_back({ p+1, INT_MAX });
    }

    void merge(node& t, node& a, node& b) {
        node tmp;
        std::merge(all(a), all(b), back_inserter(tmp));
        for (auto [l, r] : tmp) {
            if (!t.empty() && t.back()[1] >= r)
                continue;
            if (!t.empty() && t.back()[0] == l)
                t.back()[1] = r;
            else
                t.push_back({ l, r });
        }
    }

    bool check(node& v, int x, int y) {
        auto it = upper_bound(all(v), array<int, 2>({ x, INT_MAX }));
        return y >= (*prev(it))[1];
    }

    bool query(int i, int j, int x, int y) {
        bool ok = true;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) ok &= check(tree[i++], x, y);
            if((j&1) == 0) ok &= check(tree[j--], x, y);
        }
        return ok;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<array<int, 2>>> sets(N);
    for (int i = 0; i < K; i++) {
        int l, r, p;
        cin >> l >> r >> p;
        sets[p-1].push_back({ l, r });
    }

    seg_tree s(sets);

    for (int i = 0; i < M; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        bool ok = s.query(a-1, b-1, x, y);
        cout << (ok ? "yes" : "no") << endl;
    }

    return 0;
}