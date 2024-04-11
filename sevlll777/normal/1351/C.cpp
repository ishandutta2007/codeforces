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
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        set<pair<pair<int, int>, pair<int, int>>> used;
        int x = 0, y = 0;
        int ans = 0;
        for (auto c : s) {
            int x2 = x, y2 = y;
            if (c == 'N') {
                x2++;
            } else if (c == 'S') {
                x2--;
            } else if (c == 'E') {
                y2++;
            } else {
                y2--;
            }
            pair<pair<int, int>, pair<int, int>> le = {{x,  y},
                                                       {x2, y2}};
            if (used.find(le) != used.end()) {
                ans++;
            } else {
                ans += 5;
            }
            used.insert({{x,  y},
                         {x2, y2}});
            used.insert({{x2,  y2},
                         {x, y}});
            x = x2;
            y = y2;

        }
        cout << ans << '\n';
    }

}