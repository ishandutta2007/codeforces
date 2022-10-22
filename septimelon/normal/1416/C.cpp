#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
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

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int x = 0;
    ll ans = 0;
    vector<vector<int>> elems;
    elems.push_back(a);
    for (int i = 30; i >= 0; --i) {
        vector<vector<int>> nelems;
        ll inv = 0;
        ll ninv = 0;
        for (int it = 0; it < elems.size(); ++it) {
            vector<int> cou(2, 0);
            int ni = nelems.size();
            nelems.push_back(vector<int>());
            nelems.push_back(vector<int>());
            for (int j = 0; j < elems[it].size(); ++j) {
                int ca = ((elems[it][j] >> i) & 1);
                if (ca) {
                    ninv += cou[0];
                    nelems[ni + 1].push_back(elems[it][j]);
                    ++cou[1];
                }
                else {
                    inv += cou[1];
                    nelems[ni].push_back(elems[it][j]);
                    ++cou[0];
                }
            }
            for (int j = 0; j < 2; ++j) {
                if (nelems.back().size() == 0) {
                    nelems.pop_back();
                }
            }
        }
        if (inv > ninv) {
            x += (1 << i);
            ans += ninv;
        }
        else {
            ans += inv;
        }
        elems = move(nelems);
    }

    cout << ans << " " << x << "\n";

    return 0;
}