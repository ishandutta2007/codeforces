//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)3e5 + 34;
const int M = (int)1e4 + 34;

typedef long long ll;

vector<int> ad[N];
void add(int v, int l, int r, int L, int R, int x) {
    if (l >= R || L >= r) return;
    if (L <= l && r <= R) {
        //cerr << v << " <- " << x << "\n";
        ad[v].push_back(x);
        return;
    }
    int m = (l + r) / 2;
    add(v * 2 + 1, l, m, L, R, x);
    add(v * 2 + 2, m, r, L, R, x);
}

bitset<M> dp[M], ans;
int sz;

void go(int v, int l, int r) {
    int cur_sz = ad[v].size();
    for (int i = 0; i < cur_sz; i++) {
        dp[sz + 1] = (dp[sz] | (dp[sz] << ad[v][i]));
        //cout << sz + 1 << " = " << dp[sz + 1] << " ( + " << ad[v][i] << ")\n";
        sz++;
    }
    if (l + 1 == r) {
        //cout << l << " " << v << " " << dp[sz] << "\n";
        ans |= dp[sz];
    } else {
        int m = (l + r) / 2;
        go(v * 2 + 1, l, m);
        go(v * 2 + 2, m, r);
    }
    sz -= cur_sz;
}

void solve() {
    ans.reset();
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) ad[i].clear();
    sz = 0;
    int n, q, l, r, x;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> x;
        add(0, 0, n, l - 1, r, x);
    }
    go(0, 0, n);
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef MADE_BY_SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
#endif
    solve();
    return 0;
}