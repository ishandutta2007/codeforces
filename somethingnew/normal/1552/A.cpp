#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
using namespace std;
void solve(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    string s2 = s;
    sort(all(s2));
    int dif = 0;
    for (int i = 0; i < n; ++i) {
        dif += s[i] != s2[i];
    }
    cout << dif << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*
5
10 5 7 6 8
0 5 22 45 79
 */