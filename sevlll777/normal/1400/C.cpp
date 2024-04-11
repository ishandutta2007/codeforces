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
// #define int long long
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
        string s;
        cin >> s;
        int x;
        cin >> x;
        string w = "";
        bool ok = true;
        for (int i = 0; i < s.size(); i++) w += '-';
        for (int jj = 0; jj < 1; jj++) {
            for (int i = 0; i < s.size(); i++) {
                if (!ok) break;
                if (s[i] == '0') {
                    if (i >= x) {
                        if (w[i - x] == '1') ok = false;
                        if (ok)w[i - x] = '0';
                    }
                    if (i + x < s.size()) {
                        if (w[i + x] == '1') ok = false;
                        if (ok)w[i + x] = '0';
                    }
                } else {
                    if (i < x && i + x >= s.size()) ok = false;
                    if (i < x) {
                        if (i + x >= s.size() || w[i + x] == '0') ok = false;
                        if (ok) w[i + x] = '1';
                    } else if (i + x >= s.size()) {
                        if (i < x || w[i - x] == '0') ok = false;
                        if (ok)w[i - x] = '1';
                    } else {
                        if (w[i - x] == '0') {
                            if (i + x >= s.size() || w[i + x] == '0') ok = false;
                            if (ok)w[i + x] = '1';
                        }
                        if (w[i + x] == '0') {
                            if (i < x || w[i - x] == '0') ok = false;
                            if (ok)w[i - x] = '1';
                        }
                    }
                }
            }
        }
        if (!ok) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < w.size(); i++) {
                if (w[i] == '-') w[i] = '1';
            }
            cout << w << '\n';
        }
    }
}