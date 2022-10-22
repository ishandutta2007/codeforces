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
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        vector<int> l, r;
        int fi = 0;
        for (int i = 1; i < n - 1; ++i) {
            int l = i + 1, r = n;
            int cd = 0;
            while (cd < 8 && (l != 1 || r != 2)) {
                r = (r + l - 1) / l;
                if (r < l) {
                    swap(l, r);
                }
                ++cd;
            }
            if (cd == 8 && (l != 1 || r != 2)) {
                continue;
            }
            fi = i;
            break;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (i == fi) {
                continue;
            }
            l.push_back(i + 1);
            r.push_back(n);
        }
        int cl = fi + 1, cr = n;
        bool swa = false;
        while (cl != 1 || cr != 2) {
            if (swa) {
                l.push_back(fi + 1);
                r.push_back(n);
            }
            else {
                l.push_back(n);
                r.push_back(fi + 1);
            }
            cr = (cr + cl - 1) / cl;
            if (cr < cl) {
                swa = !swa;
                swap(cl, cr);
            }
        }
        cout << l.size() << "\n";
        for (int i = 0; i < l.size(); ++i) {
            cout << l[i] << " " << r[i] << "\n";
        }
    }
}