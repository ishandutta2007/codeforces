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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> lol = {0};
        for (int i = n-1; i >= 1; i--) {
            lol.pb(lol.back() + 2 * i);
        }
        for (int x = l; x <= r; x++) {
            if (x == n*(n-1)+1) {
                cout << 1 << ' ';
            } else {
                int block = (int) (lower_bound(lol.begin(), lol.end(), x) - lol.begin());
                if (x % 2 == 1) {
                    cout << block << ' ';
                } else {
                    int h = x - lol[block-1];
                    cout << h / 2 + block << ' ';
                }
            }
        }
        cout << '\n';
    }
}