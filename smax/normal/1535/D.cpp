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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, q;
    string s;
    cin >> k >> s >> q;

    vector<int> st(4 * (1 << k)), pos(1 << k);
    vector<char> sign(4 * (1 << k));
    vector<vector<int>> nodes;

    auto number = [&] (auto &self, int p, int l, int r, int d) -> void {
        if (d >= (int) nodes.size())
            nodes.emplace_back();
        nodes[d].push_back(p);
        if (l == r)
            return;
        int m = (l + r) / 2;
        self(self, 2*p, l, m, d+1);
        self(self, 2*p+1, m+1, r, d+1);
    };

    auto build = [&] (auto &self, int p, int l, int r) -> void {
        if (l == r) {
            st[p] = 1;
            return;
        }
        int m = (l + r) / 2;
        self(self, 2*p, l, m);
        self(self, 2*p+1, m+1, r);
        if (sign[p] == '0') st[p] = st[2*p];
        else if (sign[p] == '1') st[p] = st[2*p+1];
        else st[p] = st[2*p] + st[2*p+1];
    };

    number(number, 1, 0, (1 << k) - 1, 0);
    assert((int) nodes.size() == k + 1);
    int ptr = 0;
    for (int i=k-1; i>=0; i--)
        for (int u : nodes[i]) {
            sign[u] = s[ptr];
            pos[ptr++] = u;
        }
    build(build, 1, 0, (1 << k) - 1);

    vector<int> path;

    auto update = [&] (auto &self, int p, int l, int r, char c, int x, int d) -> void {
        if (p == x) {
            sign[p] = c;
            if (sign[p] == '0') st[p] = st[2*p];
            else if (sign[p] == '1') st[p] = st[2*p+1];
            else st[p] = st[2*p] + st[2*p+1];
            return;
        }
        int m = (l + r) / 2;
        if (path[d] == 2 * p) self(self, 2*p, l, m, c, x, d-1);
        else self(self, 2*p+1, m+1, r, c, x, d-1);
        if (sign[p] == '0') st[p] = st[2*p];
        else if (sign[p] == '1') st[p] = st[2*p+1];
        else st[p] = st[2*p] + st[2*p+1];
    };

    for (int i=0; i<q; i++) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        int x = pos[p];
        path.clear();
        while (x > 1) {
            path.push_back(x);
            x /= 2;
        }
        DEBUG(i, p, c, pos[p], path);
        update(update, 1, 0, (1 << k) - 1, c, pos[p], (int) path.size() - 1);
        cout << st[1] << "\n";
    }

    return 0;
}