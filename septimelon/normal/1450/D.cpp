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

vector<int> mino;

void gen(int ci, int cl, int cr, vector<int>& d) {
    if (cr - cl == 1) {
        mino[ci] = d[cl];
        return;
    }

    int mid = (cl + cr) / 2;
    gen(ci * 2 + 1, cl, mid, d);
    gen(ci * 2 + 2, mid, cr, d);
    mino[ci] = min(mino[ci * 2 + 1], mino[ci * 2 + 2]);
}

int gmin(int ci, int cl, int cr, int l, int r) {
    if (l <= cl && r >= cr) {
        return mino[ci];
    }
    if (l >= cr || r <= cl) {
        return INF;
    }
    int mid = (cl + cr) / 2;
    return min(gmin(ci * 2 + 1, cl, mid, l, r), gmin(ci * 2 + 2, mid, cr, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {

        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> inc(n + 1, false);
        int dinc = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (!inc[a[i]]) {
                inc[a[i]] = true;
                ++dinc;
            }
        }

        mino.assign(n * 4 + 5, INF);
        gen(0, 0, n, a);

        int cmi = 0, cl = 0, cr = n - 1;
        while (cr - cl >= 0) {
            if (a[cl] == cmi + 1) {
                ++cmi;
                ++cl;
            }
            else if (a[cr] == cmi + 1) {
                ++cmi;
                --cr;
            }
            else {
                break;
            }
            if (gmin(0, 0, n, cl, cr + 1) == cmi) {
                break;
            }
        }

        vector<bool> got(n, false);
        if (dinc == n) {
            got[0] = true;
        }
        for (int i = 0; i < cmi; ++i) {
            got[n - i - 1] = true;
        }
        if (gmin(0, 0, n, cl, cr + 1) == cmi + 1) {
            got[n - cmi - 1] = true;
        }

        for (int i = 0; i < n; ++i) {
            cout << got[i];
        }
        cout << "\n";

    }

    return 0;
}