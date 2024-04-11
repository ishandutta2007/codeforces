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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int couone(int v) {
    int ans = 0;
    while (v > 0) {
        ++ans;
        v &= (v - 1);
    }
    return ans;
}

void generate(map<vector<int>, int>& vtoa, vector<int> ca) {
    for (int i = 0; i < (1 << 15); ++i) {
        vector<int> cv(ca.size());
        for (int j = 0; j < ca.size(); ++j) {
            cv[j] = couone(ca[j] ^ i);
        }
        vtoa[cv] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a1[i] = (a & ((1 << 15) - 1));
        a2[i] = (a >> 15);
    }

    map<vector<int>, int> vtoa1, vtoa2;
    generate(vtoa1, a1);
    generate(vtoa2, a2);

    for (auto it = vtoa1.begin(); it != vtoa1.end(); ++it) {
        vector<int> cv = it->first;
        for (int i = 0; i < n; ++i) {
            cv[i] = 0 - cv[i];
        }
        for (int k = 0; k <= 30; ++k) {
            if (vtoa2.count(cv) > 0) {
                cout << it->second + (vtoa2[cv] << 15) << "\n";
                return 0;
            }
            for (int i = 0; i < n; ++i) {
                ++cv[i];
            }
        }
    }

    cout << "-1\n";

    return 0;
}