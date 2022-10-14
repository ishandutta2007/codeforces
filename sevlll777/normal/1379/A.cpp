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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    // Hack me!
    if (t == 93) cout << "WhoWillBeLuckyHacker?\n";
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "abacaba";
        int cnt = 0;
        for (int i = 0; i < n - t.size() + 1; i++) {
            bool ok = true;
            for (int j = 0; j < t.size(); j++) {
                if (s[i + j] != t[j]) ok = false;
            }
            if (ok) cnt++;
        }
        if (cnt > 1) {
            cout << "No";
        } else if (cnt == 1) {
            cout << "Yes\n";
            for (auto c : s) {
                if (c == '?') {
                    cout << 'z';
                } else {
                    cout << c;
                }
            }
        } else {
            vector<int> kek;
            for (int i = 0; i < n - t.size() + 1; i++) {
                bool ok = true;
                for (int j = 0; j < t.size(); j++) {
                    if (s[i + j] != t[j] && s[i + j] != '?') ok = false;
                }
                if (ok) kek.pb(i);
            }
            bool ok = false;
            for (auto i : kek) {
                string sas = s;
                for (int j = 0; j < t.size(); j++) {
                    sas[i + j] = t[j];
                }
                for (int i = 0; i < sas.size(); i++) {
                    if (sas[i] == '?') sas[i] = 'z';
                }
                cnt = 0;
                for (int i_ = 0; i_ < n - t.size() + 1; i_++) {
                    bool kok = true;
                    for (int j = 0; j < t.size(); j++) {
                        if (sas[i_ + j] != t[j]) kok = false;
                    }
                    if (kok) cnt++;
                }
                if (cnt == 1) {
                    ok = true;
                    cout << "Yes\n" << sas;
                    break;
                }
            }
            if (!ok) cout << "No";
        }
        cout << '\n';
    }
}