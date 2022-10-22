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
#include <tuple>
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
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    int ls = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i - 1].first) {
            if (ls == -1) {
                ls = i - 1;
            }
            if (a[i].first != a[ls].first) {
                cout << "YES\n" << a[ls].second << " "
                    << a[i - 1].second << " "
                    << a[ls + 1].second << " "
                    << a[i].second << "\n";
                return 0;
            }
            if (i - ls >= 3) {
                cout << "YES\n" << a[ls].second << " "
                    << a[ls + 1].second << " "
                    << a[ls + 2].second << " "
                    << a[ls + 3].second << "\n";
                return 0;
            }
        }
    }

    if (ls >= 0) {
        map<int, int> lef;
        for (int ci = 0; ci < ls; ++ci) {
            lef.insert({ a[ls].first - a[ci].first, ci });
        }
        for (int ci = ls + 2; ci < n; ++ci) {
            if (lef.count(a[ci].first - a[ls].first) > 0) {
                cout << "YES\n" << a[ls].second << " "
                    << a[ls + 1].second << " "
                    << a[lef[a[ci].first - a[ls].first]].second << " "
                    << a[ci].second << "\n";
                return 0;
            }
        }

        vector<pair<int, int>>::iterator it = a.begin();
        while (it->first != a[ls].first) {
            ++it;
        }
        ++it;
        while (n > ls + 1 && a[ls].first == a[ls + 1].first) {
            it = a.erase(it);
            --n;
        }
    }

    priority_queue<tuple<int, int, int>> dels;
    for (int i = 0; i < n - 1; ++i) {
        dels.push({ a[i].first - a[i + 1].first, 0 - i, 0 - i - 1 });
    }

    tuple<int, int, int> last({ -1, 0, 0 }), plas({ -1, 0, 0 });
    int itcou = 0;
    while (dels.size() > 0 && itcou < 2000000) {
        ++itcou;
        tuple<int, int, int> cur = dels.top();
        dels.pop();
        get<0>(cur) *= -1;
        get<1>(cur) *= -1;
        get<2>(cur) *= -1;
        //cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << "\n";

        if (get<0>(last) == get<0>(cur)) {
            if (get<2>(last) != get<1>(cur)) {
                cout << "YES\n" << a[get<1>(cur)].second << " "
                    << a[get<2>(last)].second << " "
                    << a[get<2>(cur)].second << " "
                    << a[get<1>(last)].second << "\n";
                return 0;
            }
            else {
                if (get<0>(plas) == get<0>(cur)) {
                    assert(get<2>(plas) != get<1>(cur));
                    cout << "YES\n" << a[get<1>(cur)].second << " "
                        << a[get<2>(plas)].second << " "
                        << a[get<2>(cur)].second << " "
                        << a[get<1>(plas)].second << "\n";
                    return 0;
                }
                else {
                    plas = cur;
                }
            }
        }
        else {
            last = cur;
        }

        if (get<2>(cur) < n - 1) {
            ++get<2>(cur);
            get<0>(cur) = a[get<1>(cur)].first - a[get<2>(cur)].first;
            //cout << "add " << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << "\n";
            get<1>(cur) *= -1;
            get<2>(cur) *= -1;
            dels.push(cur);
        }
    }

    cout << "NO\n";

    return 0;
}