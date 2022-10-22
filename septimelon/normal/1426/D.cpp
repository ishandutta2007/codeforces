#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    set<ll> inc({ 0 });
    ll link = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        //cout << pref[i] << " ";
        if (inc.count(pref[i]) > 0) {
            ++ans;
            inc.clear();
            inc.insert(link);
        }
        inc.insert(pref[i]);
        link = pref[i];
    }

    cout << ans << "\n";

    return 0;
}