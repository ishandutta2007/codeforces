#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, m;

struct Node {
    int x, y;
    Node(int _x = 0, int _y = 0): x(_x), y(_y) {}
};
vector<Node> vec[100005];

inline bool cmpx(Node a, Node b) {
    return a.x < b.x;
}

inline bool cmpy(Node a, Node b) {
    return a.y < b.y;
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c; read(c);
            vec[c].push_back(Node(i, j));
        }
    }
    LL ans = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (!vec[i].size()) continue;
        LL sum = 0;
        sort(vec[i].begin(), vec[i].end(), cmpx);
        for (int j = 0; j < vec[i].size(); ++j) {
            ans += 1LL * j * vec[i][j].x - sum;
            sum += vec[i][j].x;
        }
        sum = 0;
        sort(vec[i].begin(), vec[i].end(), cmpy);
        for (int j = 0; j < vec[i].size(); ++j) {
            ans += 1LL * j * vec[i][j].y - sum;
            sum += vec[i][j].y;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}