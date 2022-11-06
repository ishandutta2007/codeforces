#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pii pair<int, int>
#define pb push_back
#define kek pop_back
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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int m = *max_element(all(a));
    if (m == x) {
        cout << 1 << endl;
        return;
    }
    if (m > x) {
        for (auto &item : a) {
            if (item == x) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
        return;
    }
    cout << (x + m - 1) / m << endl;
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}