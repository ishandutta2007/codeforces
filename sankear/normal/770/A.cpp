#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <cstring>
#include <cassert>

using namespace std;

#define pb push_back
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second

using ll = long long;
using vi = vector<int>;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

string solve(int n, int k) {
    string res;
    res.resize(n);
    for (int i = 0; i < n; ++i) {
        res[i] = 'a' + i % k;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}