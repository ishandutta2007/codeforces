#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
int mod = 998244353;
struct node {
    node * left = nullptr;
    node * right = nullptr;
    int32_t val;
    int32_t y;
    int32_t add = 0;
    node(int x) {
        val = x;
        y = rand() << 16 ^ rand();
    }
};
void upd(node * v) {
    if (v == nullptr)
        return;
    if (v->left)
        v->left->add += v->add;
    if (v->right)
        v->right->add += v->add;
    v->val += v->add;
    v->add = 0;
}
node * merge(node * r1, node * r2) {
    upd(r1);
    upd(r2);
    if (r1 == nullptr)
        return r2;
    if (r2 == nullptr)
        return r1;
    if (r2->y > r1->y)
        swap(r1, r2);
    if (r1->val > r2->val) {
        r1->left = merge(r1->left, r2);
        return r1;
    } else {
        r1->right = merge(r1->right, r2);
        return r1;
    }
}
pair<node *, node *> split(node * root, int x) {
    upd(root);
    if (root == nullptr)
        return {nullptr, nullptr};
    if (root->val >= x) {
        auto [r1, r2] = split(root->left, x);
        root->left = r2;
        upd(r1);
        return {r1, root};
    } else {
        auto [r1, r2] = split(root->right, x);
        root->right = r1;
        upd(r2);
        return {root, r2};
    }
}
pair<int, node *> addf(node * root, int k) {
    auto [r1, r2] = split(root, k);
    auto [r3, r4] = split(r2, k + 1);
    bool ok = 0;
    if (r3)
        ok = 1;
    else
        r3 = new node(k);
    r2 = merge(r3, r4);
    if (r2)
        r2->add++;
    return {ok, merge(r1, r2)};
}

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int a) {
    return pow(a, mod - 2);
}
vector<int> fac;
int cnk(int n, int k) {
    return fac[n] * inv(fac[k]) % mod * inv(fac[n-k]) % mod;
}
void solve(){
    node * root = nullptr;
    int n, k;
    cin >> n >> k;
    int rs = 0;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        auto [kp, r1] = addf(root, b);
        root = r1;
        rs += 1 - kp;
    }
    cout << cnk(n + n - rs - 1, n - rs - 1) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    fac.assign(5e5, 1);
    for (int i = 1; i < fac.size(); ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}