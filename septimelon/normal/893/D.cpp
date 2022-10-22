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

const int INF = 2000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> cur;
    cur.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        cur.push_back(cur[i - 1] + a[i]);
    }
    vector<ll> msuf(n);
    msuf.back() = cur.back();
    for (int i = n - 2; i >= 0; --i) {
        msuf[i] = max(msuf[i + 1], cur[i]);
    }
    vector<ll> cmax(n);
    for (int i = 0; i < n; ++i) {
        cmax[i] = cur[i] + d - msuf[i];
    }

    int mind = 0;
    ll cv = 0;
    for (int i = 0; i < n; ++i) {
        cv += a[i];
        if (a[i] == 0) {
            if (cmax[i] < 0) {
                cout << "-1\n";
                return 0;
            }
            if (cv < 0) {
                cv = cmax[i];
                ++mind;
            }
        }
        if (cv > d) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << mind << "\n";

    return 0;
}