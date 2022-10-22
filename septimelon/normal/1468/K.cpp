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

void mov(pair<int, int>& coor, char dif) {
    if (dif == 'L') {
        --coor.first;
    } 
    if (dif == 'R') {
        ++coor.first;
    }
    if (dif == 'U') {
        ++coor.second;
    }
    if (dif == 'D') {
        --coor.second;
    }
}

pair<int, int> run(pair<int, int> dot, string& s) {
    pair<int, int> curp({ 0, 0 });
    for (int i = 0; i < s.size(); ++i) {
        auto nexp = curp;
        mov(nexp, s[i]);
        if (nexp != dot) {
            curp = nexp;
        }
    }
    return curp;
}

void solve() {
    string s;
    cin >> s;
    vector<pair<int, int>> dot;
    pair<int, int> curp({0, 0});
    int lastm = 0;
    for (int i = 0; i < s.size(); ++i) {
        mov(curp, s[i]);
        if (curp.first != 0 || curp.second != 0) {
            dot.push_back(curp);
        }
        else {
            lastm = i + 1;
        }
    }

    if (lastm == s.size() + 1) {
        cout << "100000 100000\n";
        return;
    }

    for (int i = 0; i < dot.size(); ++i) {
        if (run(dot[i], s) == pair<int, int>({ 0, 0 })) {
            cout << dot[i].first << " " << dot[i].second << "\n";
            return;
        }
    }

    cout << "0 0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}