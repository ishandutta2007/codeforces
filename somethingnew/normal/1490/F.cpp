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
    int n;
    cin >> n;
    vector<int> cnts(n + 1);
    map<int, int> mapcnt;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        mapcnt[k]++;
    }
    int cnt = 0;
    for (auto [key, val] : mapcnt) {
        cnts[val]++;
        cnt++;
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, n - cnt * i);
        cnt -= cnts[i];
    }
    cout << ans << '\n';
}
dsgrekova krutaya() {
    int n;
    cin >> n;
    while (n--)
        solve();
}