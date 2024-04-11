#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int A = 26;


enum Types{
    NONE,
    SORT,
    RSORT
};

struct Node{
    int has[A];
    Types mod;
    Node() : mod(NONE) {
        fill(has, has + A, 0);
    }
    Node(char x) : mod(NONE) {
        fill(has, has + A, 0);
        has[x - 'a'] = 1;
    }
    void print() const {
        for (int i = 0; i < A; ++i) {
            if (has[i]) {
                cerr << "i = " << (char)(i + 'a') << " has[" << (char)(i + 'a') << "] = " << has[i] << endl;
            }
        }
    }
};

Node merge(const Node& lhs, const Node& rhs) {
    // assert(lhs.mod == NONE);
    // assert(rhs.mod == NONE);
    Node ans;
    ans.mod = NONE;
    for (int i = 0; i < A; ++i) {
        ans.has[i] = lhs.has[i] + rhs.has[i];
    }
    return ans;
}

struct SegmentTree{
    int n;
    vector<Node> tree;
    SegmentTree() {}
    void build(int v, int tl, int tr, const string& s) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = Node(s[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, s);
            build(v * 2 + 1, tm, tr, s);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void push(int v, int szL, int szR) { 
        if (tree[v].mod == NONE) return;    
        tree[v * 2] = Node();
        tree[v * 2].mod = tree[v].mod;
        tree[v * 2 + 1] = Node();
        tree[v * 2 + 1].mod = tree[v].mod;

        auto pushChar = [&] (int i) {
            while (tree[v].has[i]) {
                if (szL) {
                    int add = min(szL, tree[v].has[i]);
                    szL -= add;
                    tree[v].has[i] -= add;
                    tree[v * 2].has[i] += add;
                } else {
                    assert(szR > 0);
                    int add = min(szR, tree[v].has[i]);
                    szR -= add;
                    tree[v].has[i] -= add;
                    tree[v * 2 + 1].has[i] += add;
                }
            }
        };

        if (tree[v].mod == SORT) {
            // assert(false);
            for (int i = 0; i < A; ++i) {
                pushChar(i);
            }
        } else if (tree[v].mod == RSORT) {
            for (int i = A - 1; i >= 0; --i) {
                pushChar(i);
            }
        } else {
            assert(false);
        }
        tree[v].mod = NONE;
    }
    SegmentTree(const string& s) : n(s.size()), tree(4 * n) {
        build(1, 0, n, s);
    }

    struct Info{
        int v, sz;
    };

    void upd(int v, int tl, int tr, int l, int r, vector<Info>& info) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            info.push_back({v, tr - tl});
        } else {
            int tm = (tl + tr) / 2;
            push(v, tm - tl, tr - tm);
            upd(v * 2, tl, tm, l, r, info);
            upd(v * 2 + 1, tm, tr, l, r, info);
            // tree[v] = merge(tree[v * 2], tree[v * 2 + 1]); 
        }
    } 

    void relaxUpd(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            return;
        } else {
            int tm = (tl + tr) / 2;
            relaxUpd(v * 2, tl, tm, l, r);
            relaxUpd(v * 2 + 1, tm, tr, l, r);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void upd(int l, int r, Types type) {
        vector<Info> info;
        upd(1, 0, n, l, r + 1, info);
        Node full = Node();
        for (auto [v, sz] : info) {
            full = merge(full, tree[v]);
        }

        // cerr << "full = " << endl;
        // full.print();

        // cerr << "info = " << endl;
        // for (auto [v, sz] : info) {
        //     cerr << "v = " << v << " sz = " << sz << endl;
        //     tree[v].print();
        // }

        for (auto [v, sz] : info) {
            tree[v] = Node();
            tree[v].mod = type;
        }

        if (type == RSORT) {
            reverse(all(info));
        }
        int pos = 0;
        
        for (int i = 0; i < A; ++i) {
            while (full.has[i] && pos < info.size()) {
                while (!info[pos].sz) ++pos;
                assert(pos < info.size());
                int add = min(full.has[i], info[pos].sz);
                full.has[i] -= add;
                info[pos].sz -= add;
                tree[info[pos].v].has[i] += add;
            }
        }
        
        relaxUpd(1, 0, n, l, r + 1);

        // for (auto [v, sz] : info) {
        //     v /= 2;
        //     while (v) {
        //         tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        //         v /= 2;
        //     }
        // }
    }

    void get(int v, int tl, int tr, string& ans) {
        // cerr << "v = " << v << endl;
        // tree[v].print();

        if (tl == tr - 1) {
            for (int i = 0; i < A; ++i) {
                if (tree[v].has[i]) {
                    ans += 'a' + i;
                    return;
                }
            }
            assert(false);
        } else {
            int tm = (tl + tr) / 2;
            push(v, tm - tl, tr - tm);
            get(v * 2, tl, tm, ans);
            get(v * 2 + 1, tm, tr, ans);
        }
    }

    string get() {
        string ans;
        get(1, 0, n, ans);
        return ans;
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree st(s);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        if (k == 1) {
            // sort(s.begin() + l, s.begin() + r + 1);
            st.upd(l, r, SORT);
        } else if (k == 0) {
            // sort(s.begin() + l, s.begin() + r + 1);
            // reverse(s.begin() + l, s.begin() + r + 1);
            st.upd(l, r, RSORT);
        } else {
            assert(false);
        }
    }
    string my_ans = st.get();
    // cerr << "ans = " << s << endl;
    cout << my_ans << endl;
    // assert(my_ans == s);
    return 0;
}