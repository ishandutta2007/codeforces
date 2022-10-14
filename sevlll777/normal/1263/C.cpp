#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii  pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t-- ) {
        int n; cin >> n;
        set<int> ans;
        ans.insert(0);
        for (int a = 1; a * a <= n + 20; a++) {
            ans.insert(n / a);
        }
        for (int x = 1; x * x <= n + 20; x++) {
            if (n / x != n / (x + 1)) {
                ans.insert(x);
            }
        }
        cout << ans.size() << '\n';
        for (auto g : ans) {
            cout << g << ' ';
        }
        cout << '\n';
    }
}