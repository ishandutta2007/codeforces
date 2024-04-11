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

const int INF = 1000000009;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int nx = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == x) {
            ++nx;
        }
        sum += a;
    }

    if (nx == n) {
        cout << "0\n";
    }
    else if (sum == n * x || nx >= 1) {
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}