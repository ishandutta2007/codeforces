// #pragma GCC optimize("unroll-all-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define int ll

const int INF = (is_same<int, ll>::value ? 1e18L + 666 : 1e9L + 666);

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n;
    cin >> n;
    vector<pii> points(n);
    for (auto &[x, y] : points) {
        cin >> x >> y;
    }
    points.pb(points.front());
    set<pii> st;
    for (int i = 0; i < n; ++i) {
        st.insert({points[i].first - points[i + 1].first, points[i].second - points[i + 1].second});
    }
    for (auto &[x, y] : st) {
        if (!st.count({-x, -y})) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YEs" << endl;
}