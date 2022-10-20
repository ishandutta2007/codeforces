#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizoef(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 300005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, m, a[MAXN], s[MAXN], tot;
set<pii> ban;
vector<int> vec[MAXN];
LL ans;

struct Node {
    int sum, i1, i2;
    Node(int _sum = 0, int _i1 = 0, int _i2 = 0): sum(_sum), i1(_i1), i2(_i2) {}
    bool operator < (const Node &rhs) const {
        return sum < rhs.sum;
    }
};
priority_queue<Node> pq;

void Work1(int x) {
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 0; i < vec[x].size() - 1; ++i) {
        pq.push(Node(vec[x][i] + vec[x][i + 1], i, i + 1));
    }
    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        int a = vec[x][u.i1], b = vec[x][u.i2];
        if (ban.find(make_pair(min(a, b), max(a, b))) == ban.end()) {
            ans = max(ans, 2LL * x * (a + b));
            return;
        }
        if (u.i2 != vec[x].size() - 1) {
            pq.push(Node(vec[x][u.i1] + vec[x][u.i2 + 1], u.i1, u.i2 + 1));
        }
    }
}

void Work2(int x, int y) {
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 0; i < vec[x].size(); ++i) {
        pq.push(Node(vec[x][i] + vec[y][0], i, 0));
    }
    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        int a = vec[x][u.i1], b = vec[y][u.i2];
        if (ban.find(make_pair(min(a, b), max(a, b))) == ban.end()) {
            ans = max(ans, 1LL * (x + y) * (a + b));
            return;
        }
        if (u.i2 != vec[y].size() - 1) {
            pq.push(Node(vec[x][u.i1] + vec[y][u.i2 + 1], u.i1, u.i2 + 1));
        }
    }
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        vec[i].clear();
    }
    ban.clear();
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        ban.insert(make_pair(min(u, v), max(u, v)));
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1, j; i <= n; i = j + 1) {
        for (j = i; j < n && a[j + 1] == a[i]; ++j);
        vec[j - i + 1].push_back(a[i]);
    }
    tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (vec[i].size()) {
            s[++tot] = i;
        }
    }
    ans = 0;
    for (int i = 1; i <= tot; ++i) {
        Work1(s[i]);
        for (int j = i + 1; j <= tot; ++j) {
            Work2(s[i], s[j]);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}