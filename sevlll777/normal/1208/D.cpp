#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cmath>
#define pb push_back
#define pii pair<int, int>
#define int long long
using namespace std;
const int M = 998244353;


void build_tree(vector<int> &A, vector<int> &tree, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = A[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_tree(A, tree, 2 * v + 1, tl, tm);
        build_tree(A, tree, 2 * v + 2, tm + 1, tr);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
}

void update(vector<int> &tree, int v, int l, int r, int j, int x) {
    int m = (l + r) / 2;
    if (l + 1 == r) {
        tree[v] += x;
        return;
    } else if (m > j) {
        update(tree, 2 * v + 1, l, m, j, x);
    } else {
        update(tree, 2 * v + 2, m, r, j, x);
    }
    tree[v] += x;
}

int sum(vector<int> &tree, int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) {
        return 0;
    } else if (l + 1 == r) {
        return tree[v];
    } else if (tl <= l && r <= tr) {
        return tree[v];
    } else {
        int m = (l + r) / 2;
        return sum(tree, 2 * v + 1, tl, tr, l, m) + sum(tree, 2 * v + 2, tl, tr, m, r);
    }
}

signed main() {
    int n2;
    vector<int> A;
    vector<int> B;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        A.pb(i + 1);
        B.pb(x);
    }
    int newn = pow(2, ceil(log2(n2)));
    for (int i = n2; i < newn; i++) {
        A.pb(0);
    }
    int n = newn;
    vector<int> tree(4 * n);
    vector<int> ans(n2);
    build_tree(A, tree, 0, 0, n - 1);
    for (int i = n2 - 1; i >= 0; i--) {
        int x = B[i];
        int lol = -1;
        int ror = n;
        while (ror - lol > 1) {
            int mom = (lol + ror) / 2;
            if (sum(tree, 0, 0, mom, 0, newn) > x) {
                ror = mom;
            } else {
                lol = mom;
            }
        }
        ans[i] = lol + 2;
        update(tree, 0, 0, n, lol + 1, -tree[lol + n]);
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    return 0;
}