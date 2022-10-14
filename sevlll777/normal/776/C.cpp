#pragma GCC optimize("unroll-loops")

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
#define pii pair<int, int>
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    vector<int> pows;
    if (k == 1 || k == -1) {
        pows.pb(1);
        if (k == -1) {
            pows.pb(-1);
        }
    } else {
        int hh = 1;
        while (hh < 1e17) {
            pows.pb(hh); hh *= k;
        }
    }
    int prefs = 0;
    cnt[0]++;
    int ans = 0;
    for (int i = 0 ; i < n;i++) {
        int x; cin >> x;
        prefs += x;
        cnt[prefs]++;
        for (auto p : pows) {
            ans += cnt[prefs - p];
        }
    }
    cout << ans;

}