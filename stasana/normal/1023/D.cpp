#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

typedef struct Node* pNode;
struct Node {
    int left, right;
    pNode childLeft, childRight;
    int value;

    Node(int left, int right) 
        : left(left), right(right) {
        childLeft = childRight = nullptr;
        value = 0;
    }

    void update() {
        value = min(childLeft->value, childRight->value);
    }
};

pNode build(int left, int right, vector<int>& a) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        int value = a[left];
        if (value == 0) {
            value = 1e7;
        }
        root->value = value;
        return root;
    }
    root->childLeft  = build(left, (right + left) / 2, a);
    root->childRight = build((right + left) / 2, right, a);
    root->update();
    return root;
}

int get(pNode root, int left, int right) {
    if (root->left >= right || root->right <= left) {
        return 1e7;
    }
    if (root->left >= left && root->right <= right) {
        return root->value;
    }
    return min(get(root->childLeft, left, right), get(root->childRight, left, right));
}

int main() {
    start();

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pNode root = build(0, n, a);
    vector<int> left(q + 1);
    vector<int> right(q + 1);
    vector<int> used(q + 1);
    for (int i = 0; i < n; ++i) {
        right[a[i]] = i + 1;
        used[a[i]] = 1;
    }
    for (int i = n - 1; i > -1; --i) {
        left[a[i]] = i;
    }

    for (int i = 1; i <= q; ++i) {
        if (used[i] == 1) {
            if (get(root, left[i], right[i]) != i) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (used[q] == 0 && used[0] == 0) {
        cout << "NO";
        return 0;
    }
    if (used[q] == 0) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                a[i] = q;
                break;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0) {
            a[i] = a[i - 1];
        }
    }
    for (int i = n - 2; i > -1; --i) {
        if (a[i] == 0) {
            a[i] = a[i + 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            cout << q << " ";
        }
        else {
            cout << a[i] << " ";
        }
    }
    return 0;
}