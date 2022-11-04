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

int count_ending_zeros(int n) {
    int cnt = 0;
    while (n % 2 == 0) {
        n >>= 1;
        ++cnt;
    }
    return cnt;
}

void run() {
    vector<vector<int>> nums(62);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        int l = count_ending_zeros(v);
        nums[l].pb(v);
    }
    int idx = 0;
    for (int i = 0; i < 62; ++i) {
        if (len(nums[i]) > len(nums[idx])) {
            idx = i;
        }
    }
    vector<int> ans;
    for (int i = 0; i < 62; ++i) {
        if (i == idx) {
            continue;
        }
        for (auto &x : nums[i]) {
            ans.pb(x);
        }
    }
    cout << len(ans) << endl;
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
}