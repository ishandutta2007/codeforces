#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, x;
    string s, r;
    cin >> t;
    rep(z, t) {
        cin >> s >> x;
        string r(s.size(), '1');
        rep(i, s.size())
            if (s[i] == '0') {
                if (i >= x)
                    r[i - x] = '0';
                if (i + x < s.size())
                    r[i + x] = '0';
            }
        int f = 0;
        rep(i, s.size())
            if (s[i] == '1' && (i < x || r[i - x] == '0') && (i + x >= s.size() || r[i + x] == '0'))
                f = 1;
        if (f)
            cout << "-1\n";
        else
            cout << r << '\n';
    }
}