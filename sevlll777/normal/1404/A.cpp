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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool can = true;
        for (int i = k; i < n; i++) {
            if (s[i] != s[i - k] && s[i] != '?' && s[i - k] != '?') {
                can = false;
                break;
            }
        }
        int ah = 0, uh = 0;
        for (int i = 0; i < k; i++) {
            bool zero = false, one = false;
            for (int j = i; j < n; j += k) {
                if (s[j] == '0') {
                    zero = true;
                } else if (s[j] == '1') {
                    one = true;
                }
            }
            if (zero && one) can = false;
            if (one) {
                ah++;
            } else if (!zero) {
                uh++;
            }
        }
        if (ah + uh < k / 2 || ah > k / 2) {
            can = false;
        }
        if (can) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}