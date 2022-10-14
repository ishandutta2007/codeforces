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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> dom, opm;
    for (int _ = 0; _ < n; _++) {
        int x;
        cin >> x;
        if (x > m) {
            opm.pb(x);
        } else {
            dom.pb(x);
        }
    }
    sort(dom.rbegin(), dom.rend());
    vector<int> predom = {0};
    for (int i = 0; i < dom.size(); i++) predom.pb(dom[i] + predom.back());
    sort(opm.rbegin(), opm.rend());
    int ans = 0;
    int sus = 0;
    for (int heh = 0; heh <= (int) opm.size(); heh++) {
        int ban = 0;
        if (heh > 0) ban = heh + d * (heh - 1);
        int rest = n - ban;
        if (rest >= 0) {
            ans = max(ans, sus + predom[min(rest, (int) predom.size() - 1)]);
        }
        if (heh != (int) opm.size()) sus += opm[heh];
    }
    cout << ans << '\n';
}