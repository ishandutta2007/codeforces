#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";






string compress(string a) {
    int cnt = 0;
    string b;
    for (auto x: a) {
        if (x == 'B') {
            cnt++;
        } else {
            b += x;
        }
    }
    string ans;
    if (cnt & 1) {
        ans += "B";
    }
    for (auto x: b) {
        if (!ans.empty() && ans.back() == x) {
            ans.pop_back();
        } else {
            ans += x;
        }
    }
    return ans;
}


void solve() {
    string a, b;
    cin >> a >> b;
    string sa = compress(a);
    string sb = compress(b);
    if (sa == sb) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}