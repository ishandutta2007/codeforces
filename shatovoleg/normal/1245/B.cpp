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
    int a, b, c;
    cin >> a >> b >> c;
    string seq;
    cin >> seq;
    string ans;
    int wcnt = 0;
    int ra = 0, rb = 0, rc = 0;
    for (auto &x : seq) {
        if (x == 'R') {
            ++rb;
        } else if (x == 'P') {
            ++rc;
        } else {
            ++ra;
        }
    }
    for (auto &x : seq) {
        if (x == 'R') {
            --rb;
            if (b > 0) {
                ans += 'P';
                --b;
                ++wcnt;
            } else if (c > rc) {
                ans += 'S';
                --c;
            } else {
                ans += 'R';
                --a;
            }
        } else if (x == 'P') {
            --rc;
            if (c > 0) {
                ans += 'S';
                --c;
                ++wcnt;
            } else if (a > ra) {
                ans += 'R';
                --a;
            } else {
                ans += 'P';
                --b;
            }
        } else if (x == 'S') {
            --ra;
            if (a > 0) {
                ans += 'R';
                --a;
                ++wcnt;
            } else if (b > rb) {
                ans += 'P';
                --b;
            } else {
                ans += 'S';
                --c;
            }
        }
    }
    if (wcnt >= ((n + 1) >> 1)) {
        cout << "YES" << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}