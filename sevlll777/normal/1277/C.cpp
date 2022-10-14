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
        str s;
        cin >> s;
        unset<int> kek;
        for (int i = 4; i < s.size(); i++) {
            str t = "";
            t += s[i - 4]; t += s[i - 3]; t += s[i - 2]; t += s[i - 1]; t += s[i];
            if (t == "twone") {
                kek.insert(i - 2 + 1);
            }
        }
        for (int i = 2; i < s.size(); i++) {
            str t = "";
            t += s[i - 2]; t += s[i - 1]; t += s[i];
            if (t == "two" && kek.find(i + 1) == kek.end()) {
                kek.insert(i - 1 + 1);
            }
            if (t == "one" && kek.find(i - 1) == kek.end()) {
                kek.insert(i - 1 + 1);
            }
        }
        cout << kek.size() << '\n';
        for (auto g : kek) {
            cout << g << ' ';
        }
        cout << '\n';
    }
}