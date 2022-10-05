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


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<ll> prefsum(n);
    vector<pair<ll, int>> prefind(n);
    prefsum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefsum[i] = prefsum[i-1] + a[i];
    }
    for (int i = 0; i < n; ++i) {
        prefind[i] = {prefsum[i], i};
    }
    sort(all(prefind));
    int k = prefind[n-1].second;
    for (int i = n-2; i >= 0; --i) {
        k = min(prefind[i].second, k);
        prefind[i].second = k;
    }
    ll cycleval = prefsum[n-1];
    sort(all(prefsum));
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        ll res = 0;
        if (lower_bound(all(prefsum), t) == prefsum.end()){
            if (cycleval <= 0){
                cout << -1 << ' ';
                continue;
            }
            res += ((t - prefsum.back() + cycleval - 1) / cycleval) * n;
            t -= ((t - prefsum.back() + cycleval - 1) / cycleval) * cycleval;
        }
        int k = lower_bound(all(prefsum), t) - prefsum.begin();
        res += prefind[k].second;
        cout << res << ' ';
    }
    cout << '\n';
}
dsgrekova krutaya() {
    int n;
    cin >> n;
    while (n--)
        solve();
}