#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
const int MOD = 998244353;

// 0 - does not include left or right digit
// 1 - includes left, not right
// 2 - includes right, not left
// 3 - includes both
struct Node {
    int ldigit, rdigit, len;
    long long ans[4];

    void leaf(int val) {
        ldigit = rdigit = val;
        len = ans[0] = 1;
        ans[1] = ans[2] = 0;
        ans[3] = num[val];
    }

    void Merge(Node &a, Node &b) {
        ldigit = a.ldigit;
        rdigit = b.rdigit;
        len = a.len + b.len;
        int na = (a.len == 1 ? 0 : 2), nb = (b.len == 1 ? 0 : 1);
        ans[0] = a.ans[na] * b.ans[nb] % MOD;
        ans[1] = a.ans[3] * b.ans[nb] % MOD;
        ans[2] = a.ans[na] * b.ans[3] % MOD;
        ans[3] = a.ans[3] * b.ans[3] % MOD;
        if (a.rdigit == 1) {
            na = (a.len == 1 ? 1 : 0), nb = (b.len == 1 ? 2 : 0);
            ans[na + nb] = (ans[na + nb] + a.ans[0] * b.ans[0] % MOD * num[10 * a.rdigit + b.ldigit] % MOD) % MOD;
            ans[1 + nb] = (ans[1 + nb] + a.ans[1] * b.ans[0] % MOD * num[10 * a.rdigit + b.ldigit] % MOD) % MOD;
            ans[2 + na] = (ans[2 + na] + a.ans[0] * b.ans[2] % MOD * num[10 * a.rdigit + b.ldigit] % MOD) % MOD;
            ans[3] = (ans[3] + a.ans[1] * b.ans[2] % MOD * num[10 * a.rdigit + b.ldigit] % MOD) % MOD;
        }
    }
};

struct SegmentTree {
    int n;
    string s;
    vector<Node> st;

    SegmentTree(const string &_s) : n(_s.size()), s(_s), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p].leaf(s[l] - '0');
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p].leaf(val);
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m)
            update(2*p, l, m, idx, val);
        else
            update(2*p+1, m+1, r, idx, val);
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    string c;
    cin >> n >> m >> c;

    SegmentTree st(c);
    for (int i=0; i<m; i++) {
        int x, d;
        cin >> x >> d;
        st.update(x-1, d);
        cout << st.st[1].ans[3] << "\n";
    }

    return 0;
}