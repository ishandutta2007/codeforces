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
    str s; cin >> s;
    int n = (int) s.size();
    s = " " + s;
    vector<int> flr(n + 22);
    vector<vector<int>> pref(26, flr);
    vector<vector<int>> inds(26);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) pref[j][i] = pref[j][i - 1];
        pref[s[i] - 'a'][i]++;
        inds[s[i] - 'a'].pb(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, pref[i][n]);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            int cnt = 0;
            for (auto z : inds[i]) {
                cnt += pref[j][n] - pref[j][z];
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;

}