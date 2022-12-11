#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const ll INF = (ll)(1e18) + 666;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct Node* pNode;
struct Node {
    pNode child_left, child_right;
    ll left, right;
    ll min_value, max_value;

    Node(ll left, ll right)
            : child_left(nullptr), child_right(nullptr), left(left), right(right), min_value(0), max_value(0) {}
};

pNode build(ll left, ll right, vector<ll>& a) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        root->max_value = a[left];
        root->min_value = a[left];
        return root;
    }
    root->child_left = build(left, left + right >> 1, a);
    root->child_right = build(left + right >> 1, right, a);
    root->min_value = min(root->child_left->min_value, root->child_right->min_value);
    root->max_value = max(root->child_left->max_value, root->child_right->max_value);
    return root;
}

pair<ll, ll> get(pNode root, ll left, ll right) {
    if (root->left >= right || root->right <= left) {
        return make_pair(INF, -INF);
    }
    if (root->left >= left && root->right <= right) {
        return make_pair(root->min_value, root->max_value);
    }
    pair<ll, ll> left_value = get(root->child_left, left, right);
    pair<ll, ll> right_value = get(root->child_right, left, right);
    return make_pair(min(left_value.first, right_value.first), max(left_value.second, right_value.second));
}

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    string s;
    cin >> s;
    vector<ll> xx(1);
    vector<ll> yy(1);
    ll cnt_x = 0;
    ll cnt_y = 0;
    for (char i : s) {
        if (i == 'W') {
            ++cnt_y;
        }
        if (i == 'S') {
            --cnt_y;
        }
        if (i == 'A') {
            --cnt_x;
        }
        if (i == 'D') {
            ++cnt_x;
        }
        xx.emplace_back(cnt_x);
        yy.emplace_back(cnt_y);
    }
    pNode root_x = build(0, xx.size(), xx);
    pNode root_y = build(0, yy.size(), yy);
    ll result = (root_x->max_value - root_x->min_value + 1) * (root_y->max_value - root_y->min_value + 1);
    for (int i = 1; i < (int)xx.size(); ++i) {
        pair<ll, ll> left_x = get(root_x, 0, i);
        pair<ll, ll> right_x = get(root_x, i, xx.size());
        pair<ll, ll> left_y = get(root_y, 0, i);
        pair<ll, ll> right_y = get(root_y, i, yy.size());
        for (int id = 0; id < 4; ++id) {
            ll min_x = min(left_x.first, right_x.first + dx[id]);
            ll max_x = max(left_x.second, right_x.second + dx[id]);
            ll min_y = min(left_y.first, right_y.first + dy[id]);
            ll max_y = max(left_y.second, right_y.second + dy[id]);
            min_x = min(xx[i - 1] + dx[id], min_x);
            max_x = max(xx[i - 1] + dx[id], max_x);
            min_y = min(yy[i - 1] + dy[id], min_y);
            max_y = max(yy[i - 1] + dy[id], max_y);
            min_x = min((ll)0, min_x);
            max_x = max((ll)0, max_x);
            min_y = min((ll)0, min_y);
            max_y = max((ll)0, max_y);
            result = min(result, (max_x - min_x + 1) * (max_y - min_y + 1));
        }
    }
    cout << result << endl;
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}