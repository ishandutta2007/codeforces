// #pragma GCC optimize("unroll-loops")

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
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
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
    int t; cin >> t;
    while (t--) {
        int n, p, k; cin >> n >> p >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int ans = 0;
        int suum = 0;
        for (int pref = 0; pref <= k; pref++) {
            if (suum <= p) {
                int pot = suum;
                int pans = pref;
                for (int j = k + pref - 1; j < n; j += k) {
                    if (pot + A[j] <= p) {
                        pot += A[j];
                        pans += k;
                    } else {
                        break;
                    }
                }
                ans = max(ans, pans);
                suum += A[pref];
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }


}