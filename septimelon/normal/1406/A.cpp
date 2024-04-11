#include <algorithm>
#include <cmath>
#include <ctime>
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
typedef long double ld;

const int INF = 1000000007;
const ld PI = acos(-1);
const ld EPS = 1e-13;

void solve() {
    int n;
    cin >> n;
    vector<int> c(102, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++c[a];
    }

    int ans = 0;
    int lef = 2;
    for (int i = 0; i < 102; ++i) {
        if (c[i] < lef) {
            ans += (lef - c[i]) * i;
            lef = c[i];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //srand(time(nullptr));
    //rot = max(0, rand() % 3);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}