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

int calc_f(const vector<int> &v) {
    int res = 0;
    for (auto &x : v) {
        res = (res | x) - x;
    }
    return res;
}

void run() {
    vector<int> cnt(32, 0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
        int val = x;
        for (int i = 0; i < 32; ++i) {
            cnt[i] += (val & 1);
            val >>= 1;
        }
    }
    int cur_best = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        int val = v[i];
        for (int j = 0; j < 32; ++j) {
            if (!(val & 1)) {
                val >>= 1;
                continue;
            }
            if (cnt[j] == 1) {
                cur |= (1 << j);
            }
            val >>= 1;
        }
        if (cmax(cur_best, cur)) {
            swap(v[i], v[0]);
        }
    }
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}