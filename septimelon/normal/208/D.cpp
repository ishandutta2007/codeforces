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
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<ll> c(5);
    for (int i = 0; i < 5; ++i) {
        cin >> c[i];
    }
    vector<ll> tot(5, 0);

    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += p[i];
        for (int j = 4; j >= 0; --j) {
            tot[j] += cur / c[j];
            cur %= c[j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << tot[i] << " ";
    }
    cout << "\n" << cur << "\n";

    return 0;
}