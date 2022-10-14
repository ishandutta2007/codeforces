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
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define dbl long double
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<str> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
        unmap<str, int> C1, C2;
        for (int i = 0; i < n; i++) {
            str s= A[i];
            str t = ""; t += s.front(); t += s.back();
            if (t == "00") {
                c0++;
            } else if (t == "01") {
                c1++;
                C1[s] = i + 1;
            } else if (t == "10") {
                c2++;
                C2[s] = i + 1;
            } else {
                c3++;
            }
        }
        if (c1 == 0 && c2 == 0) {
            if (c0 != 0 && c3 != 0) {
                cout << "-1\n";
            } else {
                cout << "0\n";
            }
        } else if (c1 == c2) {
            cout << "0\n";
        } else {
            vector<int> ans;
            if (c1 > c2) {
                for (auto W : C1) {
                    if (c1 - 1 > c2) {
                        str y = W.first;
                        reverse(y.begin(), y.end());
                        if (C2[y] == 0) {
                            c1--;
                            c2++;
                            ans.pb(W.second);
                        }
                    }
                }
            } else {
                for (auto W : C2) {
                    if (c2 - 1 > c1) {
                        str y = W.first;
                        reverse(y.begin(), y.end());
                        if (C1[y] == 0) {
                            c2--;
                            c1++;
                            ans.pb(W.second);
                        }
                    }
                }
            }
            cout << ans.size() << '\n';
            for (auto r : ans) {
                cout << r << ' ';
            }
            cout << '\n';
        }
    }
}