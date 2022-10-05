#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <numeric>
#include <map>
#include "stack"
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "unordered_map"
#define krutaya main
#define all(x) (x).begin(), (x).end()
#define dasha vector
#define grekova vector
#define top int
#define dsgrekova signed
typedef long long ll;
typedef long double ld;

using namespace std;

bool s2(vector<pair<ll, int>> a, int t){
    ll res = 0;
    for (int i = 0; i <= t; ++i) {
        res += a[i].first;
    }
    for (int i = t + 1; i < a.size(); ++i) {
        if (res >= a[i].first)
            res += a[i].first;
        else
            return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].second = i;
        cin >> a[i].first;
    }
    sort(all(a));
    int l = -1, r = n;
    while (l + 1 < r){
        int m = (l + r) / 2;
        if (s2(a, m))
            r = m;
        else
            l = m;
    }
    vector<int> ans;
    for (int i = r; i < n; ++i) {
        ans.push_back(a[i].second + 1);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}
dsgrekova krutaya() {
    int n;
    cin >> n;
    while (n--)
        solve();
}