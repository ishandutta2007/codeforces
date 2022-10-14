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
// #define int long long
#define str string
using namespace std;
const int M = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> lcd(n+1);
    vector<int> s;
    for (int x = 2; x <= n; x++) {
        if (lcd[x] == 0) {
            s.pb(x);
            lcd[x] = x;
        }
        for (auto p : s) {
            if (p * x <= n) {
                lcd[p * x] = p;
            } else {
                break;
            }
        }
    }
    vector<int> ans;
    for (int x = 2; x <= n; x++) {
        ans.pb(x/ lcd[x]);
    }
    sort(ans.begin(), ans.end());
    for (auto w : ans) cout << w << ' ';
}