#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;
const int M = 1000000007;
const int mx = 3e5 + 3509;
int stmin[mx][20];
int stmax[mx][20];
vector<int> pows = {1};
vector<int> logi = {0, 0};
int tree[4 * mx + 5];
vector<int> dp;

void build(vector<int> A) {
    for (int i = 0; i < 20; i++) { pows.pb(2 * pows.back()); }
    for (int i = 2; i < mx; i++) { logi.pb(1 + logi[i / 2]); }
    int n = (int) A.size();
    for (int i = 0; i < n; i++) {
        stmin[i][0] = A[i];
        stmax[i][0] = A[i];
    }
    for (int lg = 1; lg <= logi[n]; lg++) {
        for (int i = 0; i < n; i++) {
            stmin[i][lg] = min(stmin[i][lg - 1], stmin[i + pows[lg - 1]][lg - 1]);
            stmax[i][lg] = max(stmax[i][lg - 1], stmax[i + pows[lg - 1]][lg - 1]);
        }
    }
}

int ansmin(int l, int r) {
    int lg = logi[r - l + 1];
    return min(stmin[l][lg], stmin[r - pows[lg] + 1][lg]);
}

int ansmax(int l, int r) {
    int lg = logi[r - l + 1];
    return max(stmax[l][lg], stmax[r - pows[lg] + 1][lg]);
}

void buildt(int v, int l, int r) {
    if (r - l == 1) {
        if (dp[l] == -1) {
            tree[v] = 100000000;
        } else {
            tree[v] = dp[l];
        }
    } else if (l >= r) {
        return;
    } else {
        int mid = (l + r) / 2;
        buildt(2 * v + 1, l, mid);
        buildt(2 * v + 2, mid, r);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

void upd(int v, int l, int r, int pos, int x) {
    if (r - l == 1) {
        if (l == pos) {
            tree[v] = x;
        }
    } else if (l >= r) {
        return;
    } else if (l > pos || pos >= r) {
        return;
    } else {
        int mid = (l + r) / 2;
        upd(2 * v + 1, l, mid, pos, x);
        upd(2 * v + 2, mid, r, pos, x);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

int answ(int v, int l, int r, int lq, int rq) {
    if (l >= r || l >= rq || lq >= r) {
        return 10000000000;
    } else if (lq <= l && r <= rq) {
        if (tree[v] == -1) return 10000000000;
        return tree[v];
    } else {
        int mid = (l + r) / 2;
        int x1 = answ(2 * v + 1, l, mid, lq, rq);
        int x2 = answ(2 * v + 2, mid, r, lq, rq);
        return min(x1, x2);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s, l;
    cin >> n >> s >> l;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    build(A);
    dp.resize(n + 1); fill(dp.begin(), dp.end(), -1);
    for (int i = 0; i < 4 * mx + 5; i++) tree[i] = 1000000000;
    buildt(0, 0, n + 1);
    upd(0, 0, n + 1, 0, 0);
    for (int i = l - 1; i < n; i++) {
        int left = -1;
        int right = i - l + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            int mini = ansmin(mid, i);
            int maxi = ansmax(mid, i);
            if (maxi - mini <= s) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (ansmax(left + 1, i) - ansmin(left + 1, i) <= s) {
            int lel = left + 1;
            int rer = i - l + 2;
            int kek = answ(0, 0, n + 1, lel, rer);
            upd(0, 0, n + 1, i + 1, 1 + kek);
        }
    }
    int p = answ(0, 0, n + 1, n, n + 1);
    if (p >= n + 1) p = -1;
    cout << p;
}