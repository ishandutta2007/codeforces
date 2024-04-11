#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
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

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<ll> a;
    for (int i = 0; i < n; ++i) {
        ll v;
        cin >> v;
        a.push(INFL - v);
    }
    if (a.size() % 2 == 0) {
        a.push(INFL);
    }

    ll ans = 0;
    while (a.size() > 1) {
        ll c = 0;
        for (int i = 0; i < 3; ++i) {
            c += INFL - a.top();
            a.pop();
        }
        ans += c;
        a.push(INFL - c);
    }

    cout << ans << "\n";

    return 0;
}