#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <map>
#include <set>
#include <deque>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int c = abs(a - b);
        cout << c / 5 + (c % 5) / 2 + (c % 5) % 2 << '\n';
    }
}