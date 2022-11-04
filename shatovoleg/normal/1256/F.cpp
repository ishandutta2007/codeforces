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

vector<int> count_sort(const string &s) {
    vector<int> cnt(26, 0);
    for (auto &x : s) {
        ++cnt[x - 'a'];
    }
    return cnt;
}

int count_inversions(const string &s) {
    int cnt = 0;
    for (int i = 0; i < len(s); ++i) {
        for (int j = i + 1; j < len(s); ++j) {
            if (s[i] > s[j]) {
                ++cnt;
            }
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    if (count_sort(s1) != count_sort(s2)) {
        cout << "NO" << endl;
        return;
    }
    vector<int> c = count_sort(s1);
    if (*max_element(all(c)) > 1) {
        cout << "YES" << endl;
        return;
    }
    if ((count_inversions(s1) - count_inversions(s2)) % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}