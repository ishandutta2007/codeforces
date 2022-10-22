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
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }

    vector<bool> inc(n, false);
    vector<vector<int>> cyc;
    for (int i = 0; i < n; ++i) {
        if (c[i] == i || inc[i]) {
            continue;
        }
        cyc.push_back({ i });
        while (c[cyc.back().back()] != cyc.back()[0]) {
            inc[c[cyc.back().back()]] = true;
            cyc.back().push_back(c[cyc.back().back()]);
        }
    }

    vector<int> ansl, ansr;
    while (cyc.size() > 1) {
        vector<int> cl = cyc.back();
        cyc.pop_back();
        vector<int> cr = cyc.back();
        cyc.pop_back();
        ansl.push_back(cl[0]);
        ansr.push_back(cr[0]);
        for (int i = 1; i < cl.size(); ++i) {
            ansl.push_back(cl[i]);
            ansr.push_back(cr[0]);
        }
        for (int i = 1; i < cr.size(); ++i) {
            ansl.push_back(cr[i]);
            ansr.push_back(cl[0]);
        }
        ansl.push_back(cl[0]);
        ansr.push_back(cr[0]);
    }

    if (cyc.size() == 0) {
        cout << ansl.size() << "\n";
        for (int i = 0; i < ansl.size(); ++i) {
            cout << ansl[i] + 1 << " " << ansr[i] + 1 << "\n";
            swap(c[ansl[i]], c[ansr[i]]);
            c[ansl[i]] *= -1;
            c[ansr[i]] *= -1;
            /*for (int j = 0; j < n; ++j) {
                cout << c[j] << " ";
            }
            cout << "\n";*/
        }

        return 0;
    }

    int nic = 0;
    if (cyc[0].size() == 2) {
        while (nic == cyc[0][0] || nic == cyc[0][1]) {
            ++nic;
        }
        ansl.push_back(cyc[0][0]);
        ansr.push_back(nic);
        ansl.push_back(cyc[0][1]);
        ansr.push_back(nic);
        ansl.push_back(cyc[0][0]);
        ansr.push_back(nic);
    }
    else {
        int plast = cyc[0][cyc[0].size() - 2];
        int plass = cyc[0][cyc[0].size() - 3];
        ansl.push_back(plast);
        ansr.push_back(cyc[0].back());
        for (int i = 0; i < cyc[0].size() - 3; ++i) {
            ansl.push_back(cyc[0][i]);
            ansr.push_back(plast);
        }
        ansl.push_back(plass);
        ansr.push_back(cyc[0].back());
        ansl.push_back(plass);
        ansr.push_back(plast);
        ansl.push_back(plast);
        ansr.push_back(cyc[0].back());
    }

    cout << ansl.size() << "\n";
    for (int i = 0; i < ansl.size(); ++i) {
        cout << ansl[i] + 1 << " " << ansr[i] + 1 << "\n";
        swap(c[ansl[i]], c[ansr[i]]);
        c[ansl[i]] *= -1;
        c[ansr[i]] *= -1;
        /*for (int j = 0; j < n; ++j) {
            cout << c[j] << " ";
        }
        cout << "\n";*/
    }

    return 0;
}