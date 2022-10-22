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
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<set<int>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int v;
            cin >> v;
            a[i].insert(v);
        }
    }

    bool can = false;

    for (int s = 1; s < 10; ++s) {
        can = false;
        for (int i = 0; i < n; ++i) {
            if (a[i].count(s) == 0) {
                continue;
            }
            can = true;
        }
        if (!can) {
            cout << s - 1 << "\n";
            return 0;
        }
    }

    for (int s = 1; s < 10; ++s) {
        for (int d = 0; d < 10; ++d) {
            can = false;
            for (int i = 0; i < n; ++i) {
                if (a[i].count(s) == 0) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (j == i || a[j].count(d) == 0) {
                        continue;
                    }
                    can = true;
                }
            }
            if (!can) {
                cout << s * 10 + d - 1 << "\n";
                return 0;
            }
        }
    }

    for (int s = 1; s < 10; ++s) {
        for (int d = 0; d < 10; ++d) {
            for (int f = 0; f < 10; ++f) {
                can = false;
                for (int i = 0; i < n; ++i) {
                    if (a[i].count(s) == 0) {
                        continue;
                    }
                    for (int j = 0; j < n; ++j) {
                        if (j == i || a[j].count(d) == 0) {
                            continue;
                        }
                        for (int k = 0; k < n; ++k) {
                            if (k == i || k == j || a[k].count(f) == 0) {
                                continue;
                            }
                            can = true;
                        }
                    }
                }
                if (!can) {
                    cout << s * 100 + d * 10 + f - 1 << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}