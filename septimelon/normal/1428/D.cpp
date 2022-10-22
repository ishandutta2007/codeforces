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
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> ans;
    int topf = 1;
    int l3 = INF;
    vector<int> in2;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            continue;
        }
        if (a[i] == 1 && in2.size() > 0) {
            ans.push_back({ i, in2.back() });
            in2.pop_back();
            continue;
        }
        if (l3 < INF) {
            ans.push_back({ i, l3 });
            l3 = INF;
        }
        ans.push_back({ i, topf });
        if (a[i] == 3) {
            l3 = topf;
        }
        if (a[i] == 2) {
            in2.push_back(topf);
        }
        ++topf;
    }

    if (l3 < INF || in2.size() > 0 || topf > n + 1) {
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].second << " " << ans[i].first << "\n";
    }

    return 0;
}