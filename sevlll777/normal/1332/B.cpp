// #define _GLIBCXX_DEBUG
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        if (n <= 11) {
            cout << n << '\n';
            for (int j = 1; j <= n; j++) cout << j << ' ';
            cout << '\n';
        } else {
            vector<int> P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            vector<int> col(n);
            for (int x = 0; x < n; x++) {
                for (int j = 0; j < 11; j++) {
                    if (A[x] % P[j] == 0) {
                        col[x] = j+1;
                        break;
                    }
                }
            }
            vector<int> c2;
            int now = 1;
            map<int, int> sos;
            for (auto y : col) {
                if (sos.find(y) == sos.end()) {
                    sos[y] = now;
                    c2.pb(now);
                    now++;
                } else {
                    c2.pb(sos[y]);
                }
            }
            cout << now-1 << '\n';
            for (auto p : c2) cout << p << ' ';
            cout << '\n';
        }

    }
}