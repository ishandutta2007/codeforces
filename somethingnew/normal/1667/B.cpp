#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int solve(vector<int> a) {
    int n = a.size();
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<int> dp(n + 1);
    set<pair<int, int>> st;
    st.insert({0, 0});
    for (int i = 0; i < n; ++i) {
        auto lwb = st.lower_bound(pair<int, int>{pref[i + 1], -2000 * n});
        if (lwb == st.begin()) {
            dp[i + 1] = dp[i] - 1;
        } else {
            --lwb;
            dp[i + 1] = max(lwb->second + i + 1, dp[i] - 1);
        }
        if (a[i] == 0)
            dp[i + 1] = max(dp[i + 1], dp[i]);
        pair<int, int> ad = {pref[i+1], dp[i + 1] - i - 1};
        //cout << ad.first << " " << ad.second << '\n';
        auto x = st.lower_bound(ad);
        while (x != st.end() and (x->second <= ad.second)) {
            st.erase(x);
            x = st.lower_bound(ad);
        }
        x = st.lower_bound(ad);
        if (x == st.begin() and x->first != ad.first) {
            st.insert(ad);
        } else if (x->first != ad.first) {
            x--;
            if (x->second < ad.second) {
                st.insert(ad);
            }
        } else{
            if (x->second < ad.second) {
                st.insert(ad);
            }
        }

    }
    return dp.back();
}
int stup(vector<int> a) {
    int n = a.size();
    vector<int> dp(n + 1, -n-1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int sm = 0;
        for (int j = i; j < n; ++j) {
            sm += a[j];
            if (sm > 0)
                dp[j + 1] = max(dp[j+1], dp[i] + (j - i+1));
            if (sm == 0)
                dp[j + 1] = max(dp[j+1], dp[i] + 0);
            if (sm < 0)
                dp[j + 1] = max(dp[j+1], dp[i] - (j - i+1));
        }
    }
    return dp.back();
}
void gen() {
    int n = rand() % 20 + 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {

        a[i] = rand() % 50;
        a[i] -= 5;
    }
    if (stup(a) != solve(a)) {
        for (auto i : a) {
            cout << i << ' ';
        }
        exit(0);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(a) << '\n';
    }
}
/*
1
 5
 3 -3 -2 3 -2

 */