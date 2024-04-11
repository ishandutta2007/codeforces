// Megumin top

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


void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

const ll BUBEN = 666;

struct Question {
    ll left, right, index;

    bool operator< (Question other) {
        if (left / BUBEN == other.left / BUBEN) {
            if ((left / BUBEN) % 2 == 0) {
                return right < other.right;
            }
            return right > other.right;
        }
        return left < other.left;
    }
};

ll cnt[1000666];
ll res = 0;

void insert(ll x) {
    res -= cnt[x] * cnt[x] * x;
    ++cnt[x];
    res += cnt[x] * cnt[x] * x;
}

void erase(ll x) {
    res -= cnt[x] * cnt[x] * x;
    --cnt[x];
    res += cnt[x] * cnt[x] * x;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<Question> q(m);
    for (ll i = 0; i < m; ++i) {
        cin >> q[i].left >> q[i].right;
        q[i].index = i;
        --q[i].left;
    }
    sort(q.begin(), q.end());
    ll left  = 0;
    ll right = 0;
    vector<ll> result(m);
    for (auto i : q) {
        while (right < i.right) {
            insert(a[right]);
            ++right;
        }
        while (left > i.left) {
            --left;
            insert(a[left]);
        }
        while (right > i.right) {
            --right;
            erase(a[right]);
        }
        while (left < i.left) {
            erase(a[left]);
            ++left;
        }
        result[i.index] = res;
    }
    for (auto i : result) {
        cout << i << "\n";
    }
}

int main() {
    start();
    solve();
    return 0;
}