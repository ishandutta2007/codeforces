#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
#define str string
#define pb push_back
#define pii pair<int, int>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt = 0;
    vector<pii> P;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        vector<int> heh(l);
        bool f = false;
        for (int j = 0; j < l; j++){
            cin >> heh[j];
            if (j != 0 && heh[j] > heh[j - 1]) {
                f = true;
            }
        }
        if (f) {
            cnt++;
        } else {
            sort(heh.begin(), heh.end());
            P.pb({heh.front(), heh.back()});
        }
    }
    int ans = n * n;
    sort(P.begin(), P.end());
    vector<int> L, R;
    for (auto p : P) {
        L.pb(p.first); R.pb(p.second);
    }
    for (auto p : R) {
        ans -= P.size() - ((upper_bound(L.begin(), L.end(), p - 1)) - L.begin());
    }
    cout << ans;


}