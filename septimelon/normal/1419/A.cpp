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

const int INF = 1000000009;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool nn = false, cc = false;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0 && (s[i] - '0') % 2 == 1) {
            nn = true;
        }
        else if (i % 2 == 1 && (s[i] - '0') % 2 == 0) {
            cc = true;
        }
    }
    if ((n % 2 == 1 && nn) || (n % 2 == 0 && !cc)) {
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