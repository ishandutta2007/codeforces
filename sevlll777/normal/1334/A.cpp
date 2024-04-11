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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p, c;
        cin >> p >> c;
        string ans = "YES\n";

        if (p < c) {
            ans = "NO\n";
        }
        n--;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if ((x - p) < (y - c) || y < c || x < p) {
                ans = "NO\n";
            }
            p = x;
            c = y;
            if (p < c) {
                ans = "NO\n";
            }
        }
        cout << ans;
    }
}