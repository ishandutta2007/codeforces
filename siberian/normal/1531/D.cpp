#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int CLOSE = 0;
const int OPEN = 1;
const int FREE = 2;

struct Node {
    string nxt[2];
    int state;
    Node() {
        nxt[OPEN] = nxt[CLOSE] = "";
        state = FREE;
    }
    Node(const string& s) {
        if (s == "lock") {
            nxt[OPEN] = nxt[CLOSE] = "";
            state = CLOSE;
        } else if (s == "unlock") {
            nxt[OPEN] = nxt[CLOSE] = "";
            state = OPEN;
        } else {
            nxt[OPEN] = s;
            nxt[CLOSE] = "";
            state = FREE;
        }
    }
};

Node merge(const Node& a, const Node& b){
    Node ans;
    // cerr << "start = " << endl;
    for (int state = 0; state <= 1; ++state) {
        string nowColor = "";
        int nowState = state;
        if (a.nxt[nowState] != "") nowColor = a.nxt[nowState];
        if (a.state != FREE) nowState = a.state;
        if (b.nxt[nowState] != "") nowColor = b.nxt[nowState];
        if (b.state != FREE) nowState = b.state; 
        ans.nxt[state] = nowColor;
    }
    if (b.state != FREE) ans.state = b.state;
    else ans.state = a.state;
    // cerr << "end = " << endl;
    return ans;
}

struct SegmentTree{
    int n;
    vector<Node> tree;
    vector<int> pos;
    void build(int v, int tl, int tr, const vector<string>& s) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = Node(s[tl]);
            pos[tl] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, s);
        build(v * 2 + 1, tm, tr, s);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    SegmentTree() {}
    SegmentTree(const vector<string>& s) {
        n = s.size();
        // tree.resize(n);
        // for (int i = 0; i < n; ++i) {
        //     tree[i] = Node(s[i]);
        // }
        tree.resize(n * 4);
        pos.resize(n);
        build(1, 0, n, s);
    }
    void upd(int v, const string& s) {
        // tree[pos] = Node(s);
        v = pos[v];
        tree[v] = Node(s);
        v /= 2;
        while (v) {
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
            v /= 2;
        }
    }
    void outAns() {
        Node fans("blue");
        // for (int i = 0; i < n; ++i) {
        //     fans = merge(fans, tree[i]);
        // }        
        // cout << fans.nxt[OPEN] << '\n'; 
        fans = merge(fans, tree[1]);
        cout << fans.nxt[OPEN] << '\n';
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& i : s) {
        cin >> i;
    }
    SegmentTree tree(s);
    tree.outAns();
    int q;
    cin >> q;
    while (q--) {
        int pos;
        string s;
        cin >> pos >> s;
        --pos;
        tree.upd(pos, s);
        tree.outAns();
    }
    return 0;
}