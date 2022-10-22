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

#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld MEPS = EPS * 1e2;
const ll INFL = 1e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> minel;

void addElement(int ci, int cl, int cr, int fi, int a) {
    if (cr <= fi || cl > fi) {
        return;
    }
    if (cr - cl == 1) {
        string as{ to_string(a) };
        minel[ci].assign(18, INF);
        for (int i = 0; i < as.size(); ++i) {
            if (as[as.size() - i - 1] != '0') {
                minel[ci][i << 1] = a;
            }
        }
        return;
    }
    
    int nl = ci * 2 + 1;
    int nr = ci * 2 + 2;
    addElement(nl, cl, (cl + cr) / 2, fi, a);
    addElement(nr, (cl + cr) / 2, cr, fi, a);
    
    for (int i = 0; i < 18; i += 2) {
        if (minel[nl][i] <= minel[nr][i]) {
            minel[ci][i] = minel[nl][i];
            minel[ci][i + 1] = min(minel[nl][i + 1], minel[nr][i]);
        }
        else {
            minel[ci][i] = minel[nr][i];
            minel[ci][i + 1] = min(minel[nl][i], minel[nr][i + 1]);
        }
    }
}

vector<int> getMinos(int ci, int cl, int cr, int fl, int fr) {
    if (fr <= cl || fl >= cr) {
        return vector<int>(18, INF);
    }
    if (fl <= cl && fr >= cr) {
        return minel[ci];
    }

    vector<int> ans = getMinos(ci * 2 + 1, cl, (cl + cr) / 2, fl, fr);
    vector<int> rig = getMinos(ci * 2 + 2, (cl + cr) / 2, cr, fl, fr);
    
    for (int i = 0; i < 18; i += 2) {
        if (ans[i] <= rig[i]) {
            ans[i + 1] = min(ans[i + 1], rig[i]);
        }
        else {
            ans[i + 1] = min(ans[i], rig[i + 1]);
            ans[i] = rig[i];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    minel.assign(n * 4 + 5, vector<int>(18, INF));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        addElement(0, 0, n, i, a[i]);
    }

    for (int it = 0; it < m; ++it) {
        int t, a1, a2;
        cin >> t >> a1 >> a2;
        if (t == 1) {
            --a1;
            a[a1] = a2;
            addElement(0, 0, n, a1, a2);
        }
        else {
            --a1;
            vector<int> minos = getMinos(0, 0, n, a1, a2);
            int ans = 2e9 + 1;
            for (int i = 0; i < 18; i += 2) {
                if (minos[i + 1] < INF) {
                    ans = min(ans, minos[i] + minos[i + 1]);
                }
            }
            if (ans > 2e9) {
                cout << "-1\n";
            }
            else {
                cout << ans << "\n";
            }
        }
    }

    return 0;
}