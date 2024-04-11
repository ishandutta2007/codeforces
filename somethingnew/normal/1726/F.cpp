//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "random"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
mt19937 rnd;
struct node {
    node * left = nullptr;
    node * right = nullptr;
    int prtlk = 0;
    int val = 0;
    int mxinpd = 0;
    int x = 0;
    int y = 0;
    node(int xx, int vl) {
        left = nullptr;
        right = nullptr;
        x = xx;
        val = vl;
        mxinpd = val;
        y = rnd();
    }
};
int getval(node * a) {
    //cout << (a == nullptr) << endl;
    if (a == nullptr)
        return 1e18;
    return a->mxinpd + a->prtlk;
}
void prtlk(node * a) {
    if (a == nullptr)
        return;
    if (a->left) {
        a->left->prtlk += a->prtlk;
    }
    if (a->right) {
        a->right->prtlk += a->prtlk;
    }
    a->x += a->prtlk;
    a->val += a->prtlk;
    a->mxinpd = min(a->val, min(getval(a->left), getval(a->right)));
    a->prtlk = 0;
}
void upd(node * a) {
    if (a == nullptr)
        return;
    a->mxinpd = min(a->val, min(getval(a->left), getval(a->right)));
}
node * merge(node *root1, node *root2) { // root1.x < root2.x
    prtlk(root1);
    prtlk(root2);
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    if (root1->y > root2->y) {
        prtlk(root1->right);
        root1->right = merge(root1->right, root2);
        upd(root1);
        return root1;
    } else {
        prtlk(root2->left);
        root2->left = merge(root1, root2->left);
        upd(root2);
        return root2;
    }
}
pair<node *, node *> split(node * root, int k) { // [<k] [>=k]
    prtlk(root);
    if (root == nullptr) {
        return {nullptr, nullptr};
    }
    if (root->x >= k) {
        prtlk(root->left);
        auto [rl, rr] = split(root->left, k);
        root->left = rr;
        upd(root);
        return {rl, root};
    } else {
        prtlk(root->right);
        auto [rl, rr] = split(root->right, k);
        root->right = rl;
        upd(root);
        return {root, rr};
    }
}
void prtlkall(node * rt) {
    if (rt == nullptr) {
        return;
    }
    prtlk(rt);
    prtlkall(rt->left);
    prtlkall(rt->right);
}
void updseg(node * &root, int l, int r, int c) {
    auto [r1, r23] = split(root, l);
    auto [r2, r3] = split(r23, r+1);
    if (r2 != nullptr)
        r2->prtlk += c;
    prtlk(r2);
    r23 = merge(r2, r3);
    root = merge(r1, r23);
}
int getmx(node * &root, int l, int r) {
    auto [r1, r23] = split(root, l);
    auto [r2, r3] = split(r23, r+1);
    int vl = getval(r2);
    r23 = merge(r2, r3);
    root = merge(r1, r23);
    return vl;
}
void add(node * &root, int x, int val) {
    auto [r1, r23] = split(root, x);
    auto [r2, r3] = split(r23, x+1);
    if (r2 == nullptr)
        r2 = new node(x, val);
    else
        r2->val = min(r2->val, val);
    prtlk(r2);
    r23 = merge(r2, r3);
    root = merge(r1, r23);
}
void goall(node * rt, int &mxnm, int r) {
    if (rt == nullptr) {
        return;
    }
    prtlk(rt);
    goall(rt->left, mxnm, r);
    mxnm = min(mxnm, rt->val + (r - rt->x + 1));
    goall(rt->right, mxnm, r);
}

void goall2(node * rt, int &mxnm) {
    if (rt == nullptr) {
        return;
    }
    prtlk(rt);
    goall2(rt->left, mxnm);
    mxnm = min(mxnm, rt->val);
    goall2(rt->right, mxnm);
}

void delseg(node * &root, int l, int r, int t) {
    //cerr << l << ' ' << r << '\n';
    auto [r1, r23] = split(root, l);
    auto [r2, r3] = split(r23, r+1);
    int vl = 1e18;
    goall(r2, vl, r);
    root = merge(r1, r3);
    //cerr << vl << '\n';
    if (vl < 1e15)
        add(root, (r + 1) % t, vl);
}
signed main() {
    int n, t;
    cin >> n >> t;
    vector<int> g(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> c[i];
    }
    int prf = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> d[i];
        prf += d[i];
        c[i + 1] += prf;
        c[i + 1] %= t;
    }
    int res = prf;
    vector<int> points;
    for (int i = 0; i < n; ++i) {
        int p1 = g[i], p2 = t - 1;
        p1 += t - c[i];
        p2 += t - c[i];
        p1 %= t;
        p2 %= t;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back((p1+1) % t);
        points.push_back((p2+1) % t);
        points.push_back((p1-1 + t) % t);
        points.push_back((p2-1 + t) % t);
    }
    sort(all(points));
    points.erase(unique(all(points)), points.end());
    node * root = nullptr;
    for (auto i : points) {
        add(root, i, 0);
    }
    for (int i = 0; i < n; ++i) {
        int p1 = g[i], p2 = t - 1;
        p1 += t - c[i];
        p2 += t - c[i];
        p1 %= t;
        p2 %= t;
        if (p1 > p2) {
            pair<int, int> seg1 = {p1, t - 1};
            delseg(root, seg1.first, seg1.second, t);
            pair<int, int> seg2 = {0, p2};
            delseg(root, seg2.first, seg2.second, t);
        } else {
            pair<int, int> seg = {p1, p2};
            delseg(root, seg.first, seg.second, t);
        }
    }
    int beb = 1e18;
    goall2(root, beb);
    cout << res + beb;
}