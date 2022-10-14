#include <bits/stdc++.h>

#define double long double
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        nums.pb({A[i], i});
    }
    sort(all(nums));
    vector<int> a1, a2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a1.pb(nums[i].second);
        } else {
            a2.pb(nums[i].second);
        }
    }
    cout << a1.size() << '\n';
    for (auto x : a1) cout << 1+x << ' ';
    cout << '\n';
    cout << a2.size() << '\n';
    for (auto x : a2) cout << x+1 << ' ';
    cout << '\n';

}