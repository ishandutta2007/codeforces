#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 20;
int dp[N], tr[2][N * 2], mod[2][N * 2];

void push(int t, int v) {
    tr[t][v] += mod[t][v];
    if (v < N) {
        mod[t][v * 2] += mod[t][v];
        mod[t][v * 2 + 1] += mod[t][v];
    }
    mod[t][v] = 0;
}
void rel(int t, int v) {
    tr[t][v] = max(tr[t][v * 2], tr[t][v * 2 + 1]);
}

void add(int t, int cl, int cr, int d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(t, v);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[t][v] += d;
        push(t, v);
        return;
    }
    push(t, v);
    add(t, cl, cr, d, v * 2, l, (l + r) / 2);
    add(t, cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(t, v);
}
int getm(int t, int cl, int cr, int v=1, int l=0, int r=N) {
    push(t, v);
    if (cr <= l || r <= cl)
        return 0;
    if (cl <= l && r <= cr)
        return tr[t][v];
    return max(getm(t, cl, cr, v * 2, l, (l + r) / 2), getm(t, cl, cr, v * 2 + 1, (l + r) / 2, r));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, r, t, ans = 0;
    cin >> n;
    vector<int> li;
    vector<vector<int>> a;
    rep(i, n) {
        cin >> l >> r >> t;
        r++;
        t--;
        li.push_back(l);
        li.push_back(r);
        a.push_back({r, l, t});
    }
    sort(all(li));
    li.resize(unique(all(li)) - li.begin());
    sort(all(a));
    for (auto &p : a) {
        l = lower_bound(all(li), p[1]) - li.begin();
        r = lower_bound(all(li), p[0]) - li.begin();
        add(p[2], 0, l + 1, 1);
        int cd = getm(p[2], 0, l + 1);
        ans = max(ans, cd);
        if (cd > dp[r]) {
            rep(i, 2)
                add(i, r, r + 1, cd - dp[r]);
            dp[r] = cd;
        }
    }
    cout << ans;
}