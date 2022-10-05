#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int mod = 998244353;
struct node {
    int x, y;
    int cnt, sumcnt;
    int minel, maxel;
    node(int val, int q) {
        sumcnt = cnt = q;
        maxel = minel = x = val;
        y = (rand() << 15) + rand();
    }
    node * left = nullptr;
    node * right = nullptr;
};
int getscnt(node * a) {
    if (a == nullptr)
        return 0;
    return a->sumcnt;
}
void upd(node * a) {
    if (a) {
        a->sumcnt = (getscnt(a->left) + getscnt(a->right) + a->cnt) % mod;
    }
}
pair<node *, node *> split(node * root, int k) { // [<k, >=k]
    if (!root)
        return {nullptr, nullptr};
    if (root->x >= k) {
        auto [r1, r2] = split(root->left, k);
        root->left = r2;
        upd(root);
        return {r1, root};
    } else {
        auto [r1, r2] = split(root->right, k);
        root->right = r1;
        upd(root);
        return {root, r2};
    }
}
node * merge(node * root1, node * root2) {
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    if (root1->y > root2->y) {
        auto r2 = merge(root1->right, root2);
        root1->right = r2;
        upd(root1);
        return root1;
    } else {
        auto r1 = merge(root1, root2->left);
        root2->left = r1;
        upd(root2);
        return root2;
    }
}
node * add(node * root, int x, int q) {
    auto [r1, r2] = split(root, x);
    auto [r3, r4] = split(r2, x + 1);
    if (!r3)
        r3 = new node(x, q);
    else
        r3->cnt += q;
    root = merge(r1, r3);
    root = merge(root, r4);
    return root;
}
int getres = 0;
node * get(node * root, int x) {
    auto [r1, r2] = split(root, x);
    getres = getscnt(r1);
    return merge(r1, r2);
}
struct elem{
    int x, y, s;
};
int t(int x) {
    int res = 0;
    while (x) {
        res += x;
        x /= 2;
    }
    return res;
}
int qt(int a) {
    int ba = a;
    int pa = a;
    a += a / 2;
    while (1) {
        int pa2 = a;
        a += a / 2 - pa / 2;
        if (pa2 == a)
            break;
        pa = pa2;
    }
    return a - ba;
}
signed main() {
    //cout << qt(7);
    int n;
    cin >> n;
    vector<elem> a(n);
    for (auto &i : a)
        cin >> i.x >> i.y >> i.s;
    int res = a.back().x + 1;
    node * root = nullptr;
    root = add(root, 0, 1);
    while (!a.empty()) {
        root = get(root, a.back().x);
        getres += a.back().s;
        getres = qt(getres);
        res += (a.back().x - a.back().y) * getres % mod;
        res %= mod;
        root = add(root, a.back().y, getres);
        a.pop_back();
    }
    cout << res;
}