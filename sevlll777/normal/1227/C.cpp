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
const int M = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        str s;
        cin >> s;
        vector<pii> oper;
        for (int i = 0; i < 2*k-2; i++) {
            if (i % 2 == 0) {
                if (s[i] == ')') {
                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == '(') {
                            oper.pb({i + 1, j + 1});
                            str t = "";
                            for (int x = 0; x < n; x++) {
                                if (x < i || x > j) {
                                    t += s[x];
                                } else {
                                    t += s[i + j - x];
                                }
                            }
                            s = t;
                            break;
                        }
                    }
                }
            } else {
                if (s[i] == '(') {
                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == ')') {
                            oper.pb({i + 1, j + 1});
                            str t = "";
                            for (int x = 0; x < n; x++) {
                                if (x < i || x > j) {
                                    t += s[x];
                                } else {
                                    t += s[i + j - x];
                                }
                            }
                            s = t;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 2 * k - 2; i < 2 * k - 2 + n / 2 - k + 1; i++) {
            if (s[i] == ')') {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == '(') {
                        oper.pb({i + 1, j + 1});
                        str t = "";
                        for (int x = 0; x < n; x++) {
                            if (x < i || x > j) {
                                t += s[x];
                            } else {
                                t += s[i + j - x];
                            }
                        }
                        s = t;
                        break;
                    }
                }
            }
        }
        for (int i = 2 * k - 2 + n / 2 - k + 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == ')') {
                    oper.pb({i + 1, j + 1});
                    str t = "";
                    for (int x = 0; x < n; x++) {
                        if (x < i || x > j) {
                            t += s[x];
                        } else {
                            t += s[i + j - x];
                        }
                    }
                    s = t;
                    break;
                }
            }
        }
        cout << oper.size() << '\n';
        for (auto p : oper) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

}