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

    int n, m;
    cin >> n >> m;

    vector<int> color(4 * n), lazyCol(4 * n), lazyFirst(4 * n);
    vector<long long> sum(4 * n), lazyAdd(4 * n);

    auto build = [&] (auto &self, int p, int l, int r) -> void {
        if (l == r) {
            color[p] = l + 1;
            return;
        }
        int m = (l + r) / 2;
        self(self, 2*p, l, m);
        self(self, 2*p+1, m+1, r);
        color[p] = color[2*p] == color[2*p+1] ? color[2*p] : 0;
    };

    auto push = [&] (int p, int l, int r) -> void {
        if (lazyCol[p]) {
            int diff = abs(color[p] - lazyFirst[p]);
            sum[p] += (long long) (r - l + 1) * lazyAdd[p];
            color[p] = lazyCol[p];
            if (l != r) {
                lazyAdd[2*p] += lazyAdd[p] - diff + abs(lazyFirst[p] - (lazyCol[2*p] ? lazyCol[2*p] : color[2*p]));
                lazyAdd[2*p+1] += lazyAdd[p] - diff + abs(lazyFirst[p] - (lazyCol[2*p+1] ? lazyCol[2*p+1] : color[2*p+1]));
                if (lazyCol[2*p] == 0) lazyFirst[2*p] = lazyCol[p];
                if (lazyCol[2*p+1] == 0) lazyFirst[2*p+1] = lazyCol[p];
                lazyCol[2*p] = lazyCol[2*p+1] = lazyCol[p];
            }
            lazyAdd[p] = lazyCol[p] = lazyFirst[p] = 0;
        }
    };

    auto update = [&] (auto &self, int p, int l, int r, int i, int j, int x) -> void {
        push(p, l, r);
        if (i > r || j < l)
            return;
        if (i <= l && r <= j && color[p]) {
            lazyAdd[p] += abs(x - color[p]);
            lazyCol[p] = lazyFirst[p] = x;
            push(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        self(self, 2*p, l, m, i, j, x);
        self(self, 2*p+1, m+1, r, i, j, x);
        color[p] = color[2*p] == color[2*p+1] ? color[2*p] : 0;
        sum[p] = sum[2*p] + sum[2*p+1];
    };

    auto query = [&] (auto &self, int p, int l, int r, int i, int j) -> long long {
        push(p, l, r);
        if (i > r || j < l)
            return 0;
        if (i <= l && r <= j)
            return sum[p];
        int m = (l + r) / 2;
        return self(self, 2*p, l, m, i, j) + self(self, 2*p+1, m+1, r, i, j);
    };

    build(build, 1, 0, n-1);
    for (int i=0; i<m; i++) {
        int tp, l, r;
        cin >> tp >> l >> r;
        l--, r--;
        if (tp == 1) {
            int x;
            cin >> x;
            update(update, 1, 0, n-1, l, r, x);
        } else {
            cout << query(query, 1, 0, n-1, l, r) << "\n";
        }
    }

    return 0;
}