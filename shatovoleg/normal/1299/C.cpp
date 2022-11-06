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

bool cmpfrac(const pii &f1, const pii &f2) {
    return f1.first * f2.second < f2.first * f1.second;
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<int> st(1, 0);
    for (int i = 1; i < n; ++i) {
        st.pb(i);
        while (len(st) > 1 && cmpfrac({pref[i + 1] - pref[st.back()], i + 1 - st.back()}, {pref[i + 1] - pref[st[len(st) - 2]], i + 1 - st[len(st) - 2]})) {
            st.kek();
        }
    }
    st.pb(n);
    cout << fixed << setprecision(9);
    for (int i = 0; i + 1 < len(st); ++i) {
        for (int j = st[i]; j < st[i + 1]; ++j) {
            cout << (ld)(pref[st[i + 1]] - pref[st[i]]) / (st[i + 1] - st[i]) << '\n';
        }
    }
}