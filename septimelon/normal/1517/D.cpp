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
const ld MEPS = EPS * 1e2;
const ll INFL = 1e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    if (k % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "-1 ";
            }
            cout << "\n";
        }
        return 0;
    }
    vector<vector<ll>> dy(n, vector<ll>(m - 1)), dx(n - 1, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> dy[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dx[i][j];
        }
    }
    vector<vector<vector<ll>>> sk(k / 2 + 1, vector<vector<ll>>(n, vector<ll>(m, INF)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sk[0][i][j] = 0;
        }
    }
    for (int ck = 0; ck < k / 2; ++ck) {
        for (int ci = 0; ci < n; ++ci) {
            for (int cj = 0; cj < m; ++cj) {
                //cout << ck << ci << cj << endl;
                if (ci > 0) {
                    sk[ck + 1][ci - 1][cj] = min(sk[ck + 1][ci - 1][cj], sk[ck][ci][cj] + dx[ci - 1][cj] * 2);
                }
                if (ci < n - 1) {
                    sk[ck + 1][ci + 1][cj] = min(sk[ck + 1][ci + 1][cj], sk[ck][ci][cj] + dx[ci][cj] * 2);
                }
                if (cj > 0) {
                    sk[ck + 1][ci][cj - 1] = min(sk[ck + 1][ci][cj - 1], sk[ck][ci][cj] + dy[ci][cj - 1] * 2);
                }
                if (cj < m - 1) {
                    sk[ck + 1][ci][cj + 1] = min(sk[ck + 1][ci][cj + 1], sk[ck][ci][cj] + dy[ci][cj] * 2);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << sk[k / 2][i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}