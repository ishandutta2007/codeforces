// #define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> P(n), A(n+1);
        for (int i = 0; i < n; i++) {
            cin >> P[i];
            A[P[i]] = i;
        }
        string ans = "YES\n";
        int last = n - 1;
        int strt = A[1];
        for (int i = 2; i <= n; i++) {
            if (A[i] != 1 + A[i - 1]) {
                if (A[i - 1] != last) {
                    ans = "NO\n";
                    break;
                } else {
                    last = strt - 1;
                    strt = A[i];
                }
            }
        }
        cout << ans;


    }

}