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

string mini(string a, string b) {
    if (a.size() < b.size()) return a;
    if (a.size() > b.size()) return b;
    for (int c = 0; c < (int) a.size(); c++) {
        if (a[c] < b[c]) return a;
        if (a[c] > b[c]) return b;
    }
    return a;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string prev = "0";
    vector<string> ans;
    while (n--) {
        string num;
        cin >> num;
        if (prev.size() > num.size()) {
            cout << "NO\n";
            exit(0);
        } else if (num.size() > prev.size()) {
            for (int c = 0; c < num.size(); c++) {
                if (num[c] == '?') {
                    num[c] = ('0' + (c == 0));
                }
            }
        } else {
            string gg = "99999999999";
            if (mini(num, prev) == prev && num != prev) {
                int c_q = 0;
                for (auto cym : num) c_q += (cym == '?');
                if (c_q == 0) {
                    gg = num;
                }
            }
            for (int c = 0; c < num.size(); c++) {
                if ((prev[c] != '9' && num[c] == '?') || (num[c] != '?' && prev[c] < num[c])) {
                    string num2 = num;
                    if (num2[c] == '?' && prev[c] != '9') num2[c] = (char) (prev[c] + 1);
                    bool can = true;
                    for (int c0 = 0; c0 < c; c0++) {
                        if (num[c0] == '?' || num[c0] == prev[c0]) {
                            num2[c0] = prev[c0];
                        } else {
                            can = false;
                        }
                    }
                    for (int c1 = c + 1; c1 < num.size(); c1++) {
                        if (num2[c1] == '?') {
                            num2[c1] = '0';
                        }
                    }
                    if (can && (mini(num2, prev) == prev && prev != num2)) {
                        gg = mini(gg, num2);
                    }
                }
            }
            if (gg.size() > 10) {
                cout << "NO\n";
                exit(0);
            }
            num = gg;
        }
        ans.pb(num);
        prev = num;
    }
    cout << "YES\n";
    for (auto s : ans) {
        cout << s << '\n';
    }
}