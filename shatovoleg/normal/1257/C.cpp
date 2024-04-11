#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e9;

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
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}
void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        pos[v].pb(i);
    }
    int ans = INF;
    for (auto &[kek, x] : pos) {
        for (int i = 0; i + 1 < len(x); ++i) {
            cmin(ans, x[i + 1] - x[i] + 1);
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}