#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> tree;
vector<ll> lower, upper;

pair<ll, ll> getAnswer(int v, int p) {
    ll leftAns = 0, rightAns = 0;
    for (int c : tree[v]) {
        if (c == p) continue;
        auto [leftVal, rightVal] = getAnswer(c, v);
        leftAns += max(leftVal + abs(lower[c] - lower[v]), rightVal + abs(upper[c] - lower[v]));
        rightAns += max(leftVal + abs(lower[c] - upper[v]), rightVal + abs(upper[c] - upper[v]));
    }
    return make_pair(leftAns, rightAns);
}

ll solve() {
    int n; scanf("%d", &n);
    tree.assign(n, vector<int>());
    lower.assign(n, 0); upper.assign(n, 0);
    for (int i = 0; i < n; ++i) scanf("%lld %lld", &lower[i], &upper[i]);
    for (int i = 0; i < n - 1; ++i) {
        int l, r; scanf("%d %d", &l, &r);
        tree[--l].push_back(--r);
        tree[r].push_back(l);
    }
    auto [leftBest, rightBest] = getAnswer(0, -1);
    return max(leftBest, rightBest);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%lld\n", solve());
}