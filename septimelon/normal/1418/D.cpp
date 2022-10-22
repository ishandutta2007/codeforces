#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INFL = 1e18 + 5LL;
const int INF = 1000000007;
const ld PI = acos(-1);
const ld EPS = 1e-13;
const ll MOD = INFL;

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0LL) {
        d += MOD - 1;
    }
    if (d == 0LL) {
        return 1LL;
    }
    ll ans = todeg(x, d / 2LL);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

void cleque(priority_queue<pair<int, int>>& delta, const set<int>& inc) {
    while (!delta.empty()) {
        if (inc.count(delta.top().second) == 0) {
            delta.pop();
            continue;
        }
        if (inc.empty() || delta.top().second == *inc.rbegin()) {
            delta.pop();
            continue;
        }
        if (*inc.upper_bound(delta.top().second) - delta.top().second != delta.top().first) {
            delta.pop();
            continue;
        }
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<int> t(q), x(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> x[i];
    }

    set<int> inc;
    for (int i = 0; i < n; ++i) {
        inc.insert(p[i]);
    }

    priority_queue<pair<int, int>> delta;
    int lastv = 0;
    for (auto it = inc.begin(); it != inc.end(); ++it) {
        if (lastv != 0) {
            delta.push({ *it - lastv, lastv });
        }
        lastv = *it;
    }

    if (delta.size() == 0) {
        cout << "0\n";
    }
    else {
        cout << *inc.rbegin() - *inc.begin() - delta.top().first << "\n";
    }

    for (int it = 0; it < q; ++it) { //zdes nexti i previ polomany vezde
        int cx = x[it];
        set<int>::iterator iter;
        int prev;
        if (t[it] == 0) {
            inc.erase(cx);
            iter = inc.upper_bound(cx);
            if (iter != inc.begin() && iter != inc.end()) {
                --iter;
                prev = *iter;
                ++iter;
                delta.push({ *iter - prev, prev });
            }
        }
        else {
            inc.insert(cx);
            iter = inc.find(cx);
            if (iter != inc.begin()) {
                --iter;
                prev = *iter;
                ++iter;
                delta.push({ *iter - prev, prev });
            }
            ++iter;
            if (iter != inc.end()) {
                --iter;
                prev = *iter;
                ++iter;
                delta.push({ *iter - prev, prev });
            }
        }
        cleque(delta, inc);
        if (inc.size() < 2) {
            cout << "0\n";
        }
        else {
            cout << *inc.rbegin() - *inc.begin() - delta.top().first << "\n";
        }
    }

    return 0;
}