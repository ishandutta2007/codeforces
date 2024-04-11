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
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
void solve() {
    string s;
    string t;
    cin >> s >> t;
    int k = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size() - i; ++j) {
            k = j;
            if (s[i+j] != t[k])
                break;
            k++;
            if (k == t.size()) {
                cout << "Yes\n";
                return;
            }
            for (int l = 1; i + j - l >= 0; ++l) {
                //cout << k << ' ';
                if (s[i + j - l] != t[k])
                    break;
                k++;
                if (k == t.size()) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}
signed main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
/*
5
10 5 7 6 8
0 5 22 45 79
 */