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

typedef int_fast64_t ll;
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

struct Event {
    ll x, y1, y2, type;

    Event(ll x, ll y1, ll y2, ll type)
        : x(x), y1(y1), y2(y2), type(type) {}

    bool operator< (Event other) {
        return x < other.x || (x == other.x && type > other.type);
    }
};

int getId(ll value, vector<ll>& a) {
    int left  = -1;
    int right = a.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] > value) {
            right = mid;
        }
        else {
            left  = mid;
        }
    }
    return left;
}

typedef struct Node* pNode;
struct Node {
    pNode childLeft, childRight;
    ll left, right;
    ll value, delta, id;

    Node(ll left, ll right) 
        : left(left), right(right) {
        delta = value = 0;
        childLeft = childRight = nullptr;
        id = left;
    }

    void push() {
        value += delta;
        if (right - left > 1) {
            childLeft->delta += delta;
            childRight->delta += delta;
        }
        delta = 0;
    }

    void update() {
        if (childLeft->value > childRight->value) {
            id = childLeft->id;
            value = childLeft->value;
        }
        else {
            id = childRight->id;
            value = childRight->value;
        }
    }
};

pNode build(ll left, ll right) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        return root;
    }
    root->childLeft  = build(left, (left + right) / 2);
    root->childRight = build((left + right) / 2, right);
    return root;
}

void add(pNode root, int left, int right, int delta) {
    root->push();
    if (root->left >= right || root->right <= left) {
        return;
    }
    if (root->left >= left  && root->right <= right) {
        root->delta += delta;
        root->push();
        return;
    }
    add(root->childLeft, left, right, delta);
    add(root->childRight, left, right, delta);
    root->update();
}

int main() {
    start();

    int n;
    cin >> n;
    set<ll> needx;
    set<ll> needy;
    vector<Event> a;
    for (int i = 0; i < n; ++i) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        needx.insert(x1);
        needx.insert(x2);
        needy.insert(y1);
        needy.insert(y2);
        a.emplace_back(x1, y1, y2, 1);
        a.emplace_back(x2, y1, y2, -1);
    }
    vector<ll> dy;
    vector<ll> dx;
    for (auto i : needy) {
        dy.emplace_back(i);
    }
    for (int i = 0; i < a.size(); ++i) {
        a[i].y1 = getId(a[i].y1, dy);
        a[i].y2 = getId(a[i].y2, dy);
    }
    sort(a.begin(), a.end());
    pNode root = build(0, dy.size());

    for (auto i : a) {
        add(root, i.y1, i.y2 + 1, i.type);

        if (root->value >= n - 1) {
            cout << i.x << " " << dy[root->id] << endl;
            return 0;
        }
    }
    system("pause");
    return 0;
}