#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
    int zero, one, len, col;

    void apply(int c) {
        zero = (1 - c) * len;
        one = c * len;
        col = c;
    }

    Node() = default;
    Node(int c) : zero(1 - c), one(c), len(1), col(-1) {}
    Node(int zero, int one, int len, int col) : zero(zero), one(one), len(len), col(col) {}
};

Node merge(const Node &l, const Node &r) {
    return Node{l.zero + r.zero, l.one + r.one, l.len + r.len, -1};
}

vector<Node> t;

void push(int v) {
    if (t[v].col != -1) {
        t[2 * v].apply(t[v].col);
        t[2 * v + 1].apply(t[v].col);
        t[v].col = -1;
    }
}

void pull(int v) {
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void update(int v, int l, int r, int ql, int qr, int col) {
    if (ql >= r || qr <= l)
        return;
    if (l >= ql && r <= qr) {
        t[v].apply(col);
        return;
    }
    push(v);
    int m = (l + r) / 2;
    update(2 * v, l, m, ql, qr, col);
    update(2 * v + 1, m, r, ql, qr, col);
    pull(v);
}

pair<int, int> query(int v, int l, int r, int ql, int qr) {
    if (ql >= r || qr <= l)
        return {0, 0};
    if (l >= ql && r <= qr)
        return {t[v].zero, t[v].one};
    push(v);
    int m = (l + r) / 2;
    auto resl = query(2 * v, l, m, ql, qr);
    auto resr = query(2 * v + 1, m, r, ql, qr);
    return {resl.first + resr.first, resl.second + resr.second};
}

void build(int v, int l, int r, const string &s) {
    if (r - l == 1) {
        t[v] = Node{s[l] - '0'};
        // cerr << s[l] << " " << t[v].zero << " " << t[v].one << " " << t[v].len << " " << t[v].col << "\n";
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m, s);
        build(2 * v + 1, m, r, s);
        pull(v);
    }
}

void dfs(int v, int l, int r, string &res) {
    if (r - l == 1) {
        res.push_back(t[v].zero == 0 ? '1' : '0');
    } else {
        push(v);
        int m = (l + r) / 2;
        dfs(2 * v, l, m, res);
        dfs(2 * v + 1, m, r, res);
    }
}

void solve() {
    int n, q;
    string s, f;
    cin >> n >> q >> s >> f;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    swap(s, f);
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    t.resize(4 * n);
    build(1, 0, n, s);
    for (int i = 0; i < q; i++) {
        auto [zero, one] = query(1, 0, n, l[i], r[i]);
        if (zero == one) {
            cout << "NO\n";
            return;
        }
        int col = zero > one ? 0 : 1;
        update(1, 0, n, l[i], r[i], col);
        /*int zero = 0, one = 0;
        for (int j = l[i]; j < r[i]; j++) {
            zero += s[j] == '0';
            one += s[j] == '1';
        }
        int col = zero > one ? 0 : 1;
        for (int j = l[i]; j < r[i]; j++)
            s[j] = '0' + col;*/
    }
    string res = "";
    // res = s;
    dfs(1, 0, n, res);
    // cerr << res << " " << f << "\n";
    cout << (res == f ? "YES\n" : "NO\n");
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}