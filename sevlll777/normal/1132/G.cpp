#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#ifdef XLor
  #define dbg(args...) do {cout << #args << " -> "; err(args);} while (0)
#else
  #define dbg(...)
#endif
void err() {std::cout << std::endl;}
template<typename T, typename...Args>
void err(T a, Args...args){std::cout << a << ' '; err(args...);}
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 998244353;
const int inf = 1e8 + 7;
const int maxn = 1000000 + 5;

vector<int> edge[maxn];
int n, k, a[maxn], fa[maxn];

int tin[maxn], tout[maxn], tot;
void dfs(int u, int f) {
    tin[++tot] = u;
    for (int& v: edge[u]) dfs(v, u);
    tout[u] = tot;
}

ll tr[maxn << 2], tag[maxn << 2];
void pushdown(int rt) {
    ll x = tag[rt];
    tr[rt << 1] += x; tr[rt << 1 | 1] += x;
    tag[rt << 1] += x; tag[rt << 1 | 1] += x;
    tag[rt] = 0;
}
void update(int L, int R, int x, int l, int r, int rt) {
    if (L > r || R < l) return ;
    if (L <= l && r <= R) {
        tr[rt] += x; tag[rt] += x; return ;
    }
    // dbg(l, r, rt);
    int m = (l + r) >> 1; pushdown(rt);
    if (L <= m) update(L, R, x, lson);
    if (R > m) update(L, R, x, rson);
    tr[rt] = max(tr[rt << 1], tr[rt << 1 | 1]);
}

int main() {
    scanf("%d%d", &n, &k);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        while (!st.empty() && a[i] > a[st.back()]) {
            fa[st.back()] = i; 
            edge[i].push_back(st.back());
            st.pop_back();
        }
        st.push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!fa[i]) dfs(i, 0);
    for (int i = 1; i <= k; i++) update(tin[i], tout[i], 1, 1, n, 1);
    printf("%I64d ", tr[1]);
    for (int i = k + 1; i <= n; i++) {
        update(tin[i], tout[i], 1, 1, n, 1);
        update(tin[i - k], tin[i - k], -inf, 1, n, 1);
        printf("%I64d ", tr[1]);
    }
    return 0;
}