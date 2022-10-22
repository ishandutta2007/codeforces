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
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> ban;
    for (int j = 0; j < m - 1; ++j) {
        for (int i = 1; i < n; ++i) {
            if (s[i][j] == 'X' && s[i - 1][j + 1] == 'X') {
                ban.push_back(j);
                break;
            }
        }
    }
    ban.push_back(INF);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int jl, jr;
        cin >> jl >> jr;
        --jl;
        --jr;
        auto iter = lower_bound(ban.begin(), ban.end(), jl);
        if (*iter < jr) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }

    return 0;
}