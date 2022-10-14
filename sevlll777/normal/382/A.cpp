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
    str s; cin >> s;
    str t; cin >> t;
    str left = "", right = "";
    bool f = true;
    for (auto c : s) {
        if (c == '|') {
            f = false;
        } else if (f) {
            left += c;
        } else {
            right += c;
        }
    }
    int z = 0;
    while (z < t.size()) {
        if (left.size() < right.size()) {
            left += t[z];
        } else {
            right += t[z];
        }
        z += 1;
    }
    if (left.size() != right.size()) {
        cout << "Impossible";
    } else {
        cout << left << '|' << right;
    }
}