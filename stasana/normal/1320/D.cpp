// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

ll power(ll x, ll n);

const ll MOD = 2286661337;
const ll P = 1'000'000'009;
const ll Q = power(P, MOD - 2);

ll power(ll x, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n & 1) {
        return x * power(x * x % MOD, n >> 1) % MOD;
    }
    return power(x * x % MOD, n >> 1);
}

struct Result {
    ll flag_right;
    ll flag_left;
    ll hash;
    ll size;

    Result() {
        hash = size = flag_left = flag_right = 0;
    }

    Result(char ch) {
        if (ch == '0') {
            hash = 0;
            size = 1;
            flag_left = 0;
            flag_right = 0;
        }
        if (ch == '1') {
            hash = 1;
            size = 1;
            flag_left = 1;
            flag_right = 1;
        }
    }

    bool operator ==(Result other) {
        return make_pair(size, hash) == make_pair(other.size, other.hash);
    }
};

Result merge(Result left, Result right) {
    if (left.flag_right && right.flag_left) {
        left.hash = (left.hash - power(P, left.size - 1) + MOD) % MOD;
        right.hash = ((right.hash - 1 + MOD) % MOD) * Q % MOD;
        left.flag_right = 0;
        right.flag_left = 0;
        --left.size;
        --right.size;
        if (left.size == 0) {
            left = Result();
        }
        if (right.size == 0) {
            right = Result();
        }
    }
    if (left.size == 0) {
        return right;
    }
    if (right.size == 0) {
        return left;
    }
    Result result;
    result.flag_left = left.flag_left;
    result.flag_right = right.flag_right;
    result.size = left.size + right.size;
    result.hash = (left.hash + power(P, left.size) * right.hash) % MOD;
    return result;
}

typedef struct Node* pNode;
struct Node {
    pNode child_left, child_right;
    ll left, right;
    Result result;

    Node(ll left, ll right)
        : left(left), right(right) {
        child_left = child_right = nullptr;
        result = Result();
    }
};

pNode build(ll left, ll right, string& s) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        root->result = Result(s[left]);
        return root;
    }
    root->child_left = build(left, left + right >> 1, s);
    root->child_right = build(left + right >> 1, right, s);
    root->result = merge(root->child_left->result, root->child_right->result);
    return root;
}

Result get(pNode root, ll left, ll right) {
    if (root->left >= right || root->right <= left) {
        return Result();
    }
    if (root->left >= left && root->right <= right) {
        return root->result;
    }
    return merge(get(root->child_left, left, right), get(root->child_right, left, right));
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    pNode root = build(0, n, s);
    ll m;
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll left_1, left_2, len;
        cin >> left_1 >> left_2 >> len;
        --left_1;
        --left_2;
        Result x = get(root, left_1, left_1 + len);
        Result y = get(root, left_2, left_2 + len);
        if (x == y) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}