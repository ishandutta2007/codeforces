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
vector<ll> kbs;
void solve(){
    ll x;
    cin >> x;
    for (ll i = 1; i * i * i < x; ++i) {
        ll k = x - i * i * i;
        if (*lower_bound(all(kbs), k) == k){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
dsgrekova krutaya() {
    int n;
    for (ll i = 1; i < 1e5; ++i) {
        kbs.push_back(i * i * i);
    }
    cin >> n;
    while (n--)
        solve();
}