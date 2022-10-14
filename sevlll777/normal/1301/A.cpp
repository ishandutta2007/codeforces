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
#define str string
using namespace std;
const int M = 1000000007;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        str a, b, c; cin >> a >> b >> c;
        str ans = "YES";
        for (int i = 0; i < (int) a.size(); i++) {
            if ((a[i] == b[i] && a[i] != c[i]) || (a[i] != c[i] && b[i] != c[i])) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '\n';
    }
}