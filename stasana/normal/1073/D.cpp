//    -
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;

typedef struct Node* pNode;
struct Node {
    pNode childLeft, childRight;
    ll value;
    ll left, right;

    Node(ll left, ll right)
        : left(left), right(right) {
        value = 0;
        childLeft = childRight = nullptr;
    }
};

pNode build(ll left, ll right, vector<ll>& a) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        root->value = a[left];
        return root;
    }
    root->childLeft = build(left, (left + right) / 2, a);
    root->childRight = build((left + right) / 2, right, a);
    root->value = root->childLeft->value + root->childRight->value;
    return root;
}

ll get(pNode root, ll left, ll right) {
    if (root->left >= right || root->right <= left) {
        return 0;
    }
    if (root->left >= left && root->right <= right) {
        return root->value;
    }
    return get(root->childLeft, left, right) + get(root->childRight, left, right);
}

void update(pNode root, ll index) {
    if (root->left > index || root->right <= index) {
        return;
    }
    if (root->right - root->left == 1) {
        root->value = 0;
        return;
    }
    update(root->childLeft, index);
    update(root->childRight, index);
    root->value = root->childLeft->value + root->childRight->value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    ll n, T;
    cin >> n >> T;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<ll> need(n + 1, 1);
    pNode root1 = build(1, n + 1, a);
    pNode root2 = build(1, n + 1, need);
    ll cnt = n;
    ll i = 1;
    ll res = 0;
    while (cnt > 0) {
        ll sum = get(root1, 0, n + 1);
        res += (T / sum) * cnt;
        T %= sum;
        ll left = i - 1;
        ll right = n + 1;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (get(root1, i, mid + 1) <= T) {
                left = (left + right) / 2;
            }
            else {
                right = (left + right) / 2;
            }
        }
        if (get(root1, i, left + 1) <= T) {
            T -= get(root1, i, left + 1);
            res += get(root2, i, left + 1);
        }
        else {
            update(root1, i);
            update(root2, i);
            --cnt;
        }
        i = left + 1;
        if (i == n + 1) {
            i = 1;
        }
        else {
            update(root1, i);
            update(root2, i);
            --cnt;
            ++i;
            if (i == n + 1) {
                i = 1;
            }
        }
    }
    cout << res;
    return 0;
}