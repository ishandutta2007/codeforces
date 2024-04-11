#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int INF = 1e9;

int comb[1 << 5][1 << 5];
bool bad[1 << 5][1 << 5];

struct SegmentTree {
    struct Node {
        int ans[1 << 5];

        void leaf(char c) {
            memset(ans, 63, sizeof(ans));
            ans[1] = c != 'a';
            ans[2] = c != 'b';
            ans[4] = c != 'c';
        }

        void pull(const Node &a, const Node &b) {
            memset(ans, 63, sizeof(ans));
            for (int i=1; i<1<<5; i++)
                if (a.ans[i] < INF)
                    for (int j=1; j<1<<5; j++)
                        if (b.ans[j] < INF && !bad[i][j])
                            ans[comb[i][j]] = min(ans[comb[i][j]], a.ans[i] + b.ans[j]);
        }
    };

    int n;
    string s;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), s(n, 'a'), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const string &_s) : n((int) _s.size()), s(_s), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p].leaf(s[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    // Node query(int p, int l, int r, int i, int j) {
    //     if (l == i && r == j)
    //         return st[p];
    //     int m = (l + r) / 2;
    //     if (j <= m)
    //         return query(2*p, l, m, i, j);
    //     else if (i > m)
    //         return query(2*p+1, m+1, r, i, j);
    //     Node ret, ls = query(2*p, l, m, i, m), rs = query(2*p+1, m+1, r, m+1, j);
    //     ret.pull(ls, rs);
    //     return ret;
    // }

    // int query(int i, int j) {
    //     return query(1, 0, n-1, i, j).ans;
    // }

    void update(int p, int l, int r, int idx, char c) {
        if (l == r) {
            st[p].leaf(c);
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m)
            update(2*p, l, m, idx, c);
        else
            update(2*p+1, m+1, r, idx, c);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int idx, char c) {
        update(1, 0, n-1, idx, c);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i=1; i<1<<5; i++)
        for (int j=1; j<1<<5; j++) {
            comb[i][j] = i | j;
            if (i & 1 && j & 2)
                comb[i][j] |= 8;
            if (i & 2 && j & 4)
                comb[i][j] |= 16;
            bad[i][j] = (i & 1 && j & 16) || (i & 8 && j & 4);
        }

    int n, q;
    string s;
    cin >> n >> q >> s;
    SegmentTree st(s);
    for (int i=0; i<q; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        st.update(pos, c);
        cout << *min_element(st.st[1].ans, st.st[1].ans + (1 << 5)) << "\n";
    }

    return 0;
}