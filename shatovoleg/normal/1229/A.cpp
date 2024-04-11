#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif
 
void run();
 
signed main() {
    // UseFiles("shelves");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n;
    cin >> n;
    vector<pii> items(n);
    for (auto &x : items) {
        cin >> x.first;
    }
    for (auto &x : items) {
        cin >> x.second;
    }
    vector<int> taken(n, 0);
    vector<int> masks;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (items[i].first == items[j].first && !taken[i] && !taken[j]) {
                masks.pb(items[i].first);
                taken[i] = 1;
                taken[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &x : masks) {
            if ((x & items[i].first) == items[i].first) {
                taken[i] = 1;
            }
        }
    }
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        if (taken[i]) {
            sm += items[i].second;
        }
    }
    cout << sm << endl;
}