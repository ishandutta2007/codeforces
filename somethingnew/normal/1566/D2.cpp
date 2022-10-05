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
using namespace std;
struct node{
    int x, y;
    node * left = nullptr;
    node * right = nullptr;
    int sz = 1;
    int szsum = 1;
    node(int val) {
        x = val;
        y = (rand() << 15) ^ rand();
    }
};
inline int getsz(node * root) {
    return root ? root->szsum : 0;
}
inline void upd(node * root) {
    root->szsum = root->sz + getsz(root->left) + getsz(root->right);
}
pair<node *, node *> split(node * root, int k) {
    if (root == nullptr)
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
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    if (root1->y < root2->y) {
        root1->right = merge(root1->right, root2);
        upd(root1);
        return root1;
    } else {
        root2->left = merge(root1, root2->left);
        upd(root2);
        return root2;
    }
}
void add(node *& root, int x) {
    auto [r1, r23] = split(root, x);
    auto [r2, r3] = split(r23, x + 1);
    if (r2 == nullptr)
        r2 = new node(x);
    else {
        r2->sz++;
        r2->szsum++;
    }
    root = merge(r1, merge(r2, r3));
}
void erase(node *& root, int x) {
    auto [r1, r23] = split(root, x);
    auto [r2, r3] = split(r23, x + 1);
    if (r2 != nullptr) {
        r2->sz--;
        r2->szsum--;
    }
    if (r2->sz == 0)
        root = merge(r1, r3);
    else
        root = merge(r1, merge(r2, r3));
}
int getless(node *& root, int x) {
    auto [r1, r2] = split(root, x + 1);
    int val = getsz(r1);
    root = merge(r1, r2);
    return val;
}
int getmore(node *& root, int x) {
    auto [r1, r2] = split(root, x);
    int val = getsz(r2);
    root = merge(r1, r2);
    return val;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n * m);
    map<int, vector<int>> order;
    for (int i = 0; i < n * m; ++i) {
        cin >> nums[i];
        order[nums[i]].push_back(i);
    }
    vector<int> order2;
    for (auto [key, val] : order) {
        int t0 = 0;
        while (t0 != val.size()) {
            int k = 1;
            for (; t0 + k < val.size(); ++k) {
                if ((k + order2.size()) % m == 0) {
                    break;
                }
            }
            for (int i = k - 1; i >= 0; --i) {
                order2.push_back(val[i + t0]);
            }
            t0 += k;
        }
    }
    vector<vector<int>> pole(n, vector<int>(m));
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        node * rt = nullptr;
        for (int j = 0; j < m; ++j) {
            //cerr << order2[i * m + j] << ' ';
            pole[i][j] = order2[i * m + j];
            res += getless(rt, pole[i][j]);
            add(rt, pole[i][j]);
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}