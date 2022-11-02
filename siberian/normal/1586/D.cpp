#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

// #define LOCAL

int n;

#ifdef LOCAL

const int N = 110;
int p[N];

#endif

int query(const vector<int>& a) {
    assert(a.size() == n);
    cout << "?";
    for (auto i : a) {
        cout << ' ' << i;
    }
    cout << endl;
    int ans;
    #ifdef LOCAL
        for (int i = 0; i < n; ++i) {
            cerr << p[i] + a[i] << " ";
        }
        cerr << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (p[i] + a[i] == p[j] + a[j]) {
                    ans = i + 1;
                    return ans;
                }
            }
        }
        ans = 0;
    #else
        cin >> ans;
    #endif
    return ans;
}

int findLast() {
    vector<int> a(n, n);
    for (int x = n; x >= 2; --x) {
        a[n - 1] = n + 1 - x;
        if (query(a) > 0) {
            return x;
        }
    }
    return 1;
}

void outAns(const vector<int>& ans) {
    cout << "!";
    for (auto i : ans) {
        cout << ' ' << i;
    }
    cout << endl;
    #ifdef LOCAL
    for (int i = 0; i < n; ++i) {
        assert(p[i] == ans[i]);
    }
    #endif
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    #ifdef LOCAL
        n = 5;
        p[0] = 3;
        p[1] = 2;
        p[2] = 1;
        p[3] = 5;
        p[4] = 4;
    #else
        cin >> n;
    #endif
    int last = findLast();
    #ifdef LOCAL
        cerr << "last = " << last << endl; 
        assert(last == p[n - 1]);
    #endif
    vector<int> ans(n);
    ans[n - 1] = last;
    vector<int> a(n, last);
    for (int x = 1; x <= n; ++x) {
        if (x == last) continue;
        a[n - 1] = x;
        int pos = query(a);
        assert(pos > 0);
        ans[pos - 1] = x;
    }
    outAns(ans);
    return 0;
}