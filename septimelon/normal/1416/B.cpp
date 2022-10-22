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

void upd(int i, int v, map<int, int>& last, map<int, int>& mdist) {
    if (last.count(v) == 0) {
        last[v] = i;
        mdist[v] = i + 1;
    }
    else {
        mdist[v] = max(mdist[v], i - last[v]);
        last[v] = i;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }   
    if (sum % n != 0) {
        cout << "-1\n";
        return;
    }

    int ave = sum / n;
    vector<int> ai, aj, ax;
    for (int i = 1; i < n; ++i) {
        ai.push_back(1);
        aj.push_back(i + 1);
        ax.push_back(((a[i] - 1) / (i + 1) + 1) * (i + 1) - a[i]);
        ai.push_back(i + 1);
        aj.push_back(1);
        ax.push_back(((a[i] - 1) / (i + 1) + 1));
    }
    for (int i = 1; i < n; ++i) {
        ai.push_back(1);
        aj.push_back(i + 1);
        ax.push_back(ave);
    }

    cout << ai.size() << "\n";
    for (int i = 0; i < ai.size(); ++i) {
        cout << ai[i] << " " << aj[i] << " " << ax[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}