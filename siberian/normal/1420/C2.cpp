#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, q;
vector<int> a;

void read() {
    cin >> n >> q;
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
    }
}

const ll INF = -1e18;

struct Node{
    ll dp[2][2];
    int sz;
    Node() {
        sz = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = INF;
            }
        }
    }
    Node(int x) {
        dp[0][0] = x;
        dp[0][1] = INF;
        dp[1][0] = INF;
        dp[1][1] = -x;
        sz = 1;
    }
};

Node merge(const Node& a, const Node& b) {
    if (a.sz == 0) return b;
    if (b.sz == 0) return a;
    Node ans;
    ans.sz = a.sz + b.sz;
    for (int aL = 0; aL <= 1; ++aL) {
        for (int aR = 0; aR <= 1; ++aR) {
            chkmax(ans.dp[aL][aR], a.dp[aL][aR]);
            chkmax(ans.dp[aL][aR], b.dp[aL][aR]);
            if (a.dp[aL][aR] == INF) continue;
            int bL = 1 - aR;
            for (int bR = 0; bR <= 1; ++bR) {
                if (b.dp[bL][bR] == INF) continue;
                chkmax(ans.dp[aL][bR], a.dp[aL][aR] + b.dp[bL][bR]);
            }
        }
    }
    return ans;
}

struct SegmentTree{
    int n;
    vector<int> pos;
    vector<Node> tree;
    SegmentTree() {}
    
    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = Node(a[tl]);
            //cout << "v = " << v << " tl = " << tl << " a[tl] = " << a[tl] << endl;
            pos[tl] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.assign(n * 4, {});
        pos.assign(n, 0);
        build(1, 0, n, a);
    }

    void upd(int v, int val) {
        v = pos[v];
        tree[v] = Node(val);
        v /= 2;
        while (v) {
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
            v /= 2;
        }
    }

    ll getAns() {
        return max(tree[1].dp[0][0], tree[1].dp[0][1]);
    }

    void wr() {
        cout << "tree = " << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << "v = " << i << endl;
            cout << "dp = " << endl;
            for (int x = 0; x <= 1; ++x) {
                for (int y = 0; y <= 1; ++y) {
                    cout << tree[i].dp[x][y] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};

SegmentTree tree;

void build() {
    tree = SegmentTree(a);
    //tree.wr();
}

void upd(int l, int r) {
    swap(a[l], a[r]);
    tree.upd(l, a[l]);
    tree.upd(r, a[r]);
}

ll getAns() {
    return tree.getAns();
}

void run() {
    build();
    cout << getAns() << "\n";
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        upd(l, r);
        cout << getAns() << "\n";
    }
}

void write() {

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        read();
        run();
    }
    return 0;
}