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
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                cnt++;
            }
        }
    }
    int m; cin >> m;
    bool ans = true;
    if (cnt % 2 == 0) ans = false;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if ((4 + r - l) % 4 == 1 || (4 + r - l) % 4 == 2) {
            ans = !ans;
        }
        if (ans) {
            cout << "odd\n";
        } else {
            cout << "even\n";
        }
    }
}