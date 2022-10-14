#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
// #define int short
#define str string
#define pb push_back
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        str ans = "";
        if (n % 2 == 0) {
            for (int _ = 0; _ < n / 2; _++) {
                cout << "1";
            }
        } else {
            cout << "7";
            for (int _ = 0; _ < n / 2 - 1; _++) {
                cout << "1";
            }
        }
        cout << '\n';
    }
}