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
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1000000007;
vector<pii> tree(7e6);
int newn;
vector<int> B;
 
void build_tree(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = {B[l], l};
    } else if (l + 1 < r) {
        int m = (l + r) / 2;
        build_tree(2 * v + 1, l, m);
        build_tree(2 * v + 2, m, r);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
}
 
void update(int v, int l, int r, int qu_l, int x) {
    if (l > qu_l) {
        return;
    }
    if (qu_l >= r) {
        return;
    }
    if (l >= r) {
        return;
    }
    if (l == qu_l && l + 1 == r) {
        tree[v].first += x;
        return;
    }
    int m = (l + r) / 2;
    update(2 * v + 1, l, m, qu_l, x);
    update(2 * v + 2, m, r, qu_l, x);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}
 
pii get_ans(int v, int l, int r, int qu_l, int qu_r) {
    if (l + 1 > r) {
        return {1e9, 1e9};
    }
    if (l >= qu_r || r <= qu_l) {
        return {1e9, 1e9};
    }
    if (l >= qu_l && qu_r >= r) {
        return tree[v];
    } else {
        int m = (l + r) / 2;
        pii ans1 = get_ans(2 * v + 1, l, m, qu_l, qu_r);
        pii ans2 = get_ans(2 * v + 2, m, r, qu_l, qu_r);
        return min(ans1, ans2);
    }
}
 
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, x;
    cin >> q >> x;
    int ans = 0;
    newn = 1048576;
    B.resize(x);
    for (int p = x; p < newn; p++) B.pb(1e9);
    build_tree(0, 0, newn);
    for (int i = 0; i < q; i++) {
        int y; cin >> y;
        y %= x;
        update(0, 0, newn, y, 1);
        pii lol = get_ans(0, 0, newn, 0, newn);
        cout << lol.first * x + lol.second << '\n';
    }
 
}