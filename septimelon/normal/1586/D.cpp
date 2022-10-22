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

int ask(int ind, bool is_hig, int n) {
    cout << "?";
    if (is_hig) {
        for (int i = 0; i < n; ++i) {
            if (i == ind) {
                cout << " 1";
            }
            else {
                cout << " 2";
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (i == ind) {
                cout << " 2";
            }
            else {
                cout << " 1";
            }
        }
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nex(n, -1);
    vector<int> pre(n, -1);

    for (int i = n - 1; i >= 0; --i) {
        if (nex[i] == -1) {
            int ans{ ask(i, false, n) };
            if (ans != -1) {
                nex[i] = ans;
                pre[ans] = i;
            }
        }
        if (pre[i] == -1) {
            int ans{ ask(i, true, n) };
            if (ans != -1) {
                pre[i] = ans;
                nex[ans] = i;
            }
        }
    }

    int firs{ 0 };
    for (int i = 0; i < n; ++i) {
        if (pre[i] == -1) {
            firs = i;
            break;
        }
    }

    vector<int> ans(n);
    int nv{ 1 };
    while (firs != -1) {
        ans[firs] = nv;
        firs = nex[firs];
        ++nv;
    }

    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}