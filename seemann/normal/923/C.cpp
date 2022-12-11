#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const int MAXN = 1e5;

struct Node {
    Node* go[2];
    Node* parent;
    int parentb;
    int count;
    Node(Node* parent, int parentb) : parent(parent), parentb(parentb), count(0) {
        go[0] = go[1] = nullptr;
    }

    bool empty() const {
        return go[0] == nullptr && go[1] == nullptr;
    }
};
Node* root = new Node(nullptr, 0);
const int MAXB = 29;

void add(int x) {
    Node* cur = root;
    for (int i = MAXB; i >= 0; --i) {
        cur->count++;
        int b = (x >> i) & 1;
        if (cur->go[b] == nullptr) {
            cur->go[b] = new Node(cur, b);
        }
        cur = cur->go[b];
    }
    cur->count++;
}

int find(int p) {
    Node* cur = root;
    int res = 0;
    for (int i = MAXB; i >= 0; --i) {
        cur->count--;
        int b = (p >> i) & 1;
        if (cur->go[b] == nullptr) {
            b = 1 - b;
        }
        res ^= (b << i);
        cur = cur->go[b];
    }
    cur->count--;

    while (cur != nullptr) {
        if (cur->count > 0) {
            break;
        }

        Node * parent = cur->parent;
        if (parent != nullptr) {
            parent->go[cur->parentb] = nullptr;
        }

        Node * todel = cur;

        cur = parent;
        delete todel;
    }

    return res ^ p;
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }

    forn(i, n) {
        int x;
        cin >> x;
        add(x);
    }

    forn(i, n) {
        cout << find(a[i]) << ' ';
    }
    cout << '\n';
    
    return 0;
}