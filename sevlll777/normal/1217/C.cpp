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

using namespace std;
#define pb push_back
#define int long long
#define pii pair<int, int>


signed main() {
    int q;
    cin >> q;
    for (int __ = 0; __ < q; __++) {
        string s;
        cin >> s;
        vector<int> Z;
        Z.pb(0);
        int zc = 0;
        for (auto w : s) {
            Z.pb(zc);
            if (w == '0') {
                zc++;
            } else {
                zc = 0;
            }
        }
        int x = ceil(log2(s.size()));
        int ans = 0;
        for (int d = 0; d <= x; d++) {
            for (int st = 1; st <= s.size() - d; st++) {
                if (s[st - 1] == '1') {
                    int num = 0;
                    for (int x = st - 1; x < st + d; x++) {
                        num *= 2;
                        num += (s[x] - '0');
                    }
                    if (Z[st] >= num - d - 1) {
                        ans++;
                    }
                }
            }

        }
        cout << ans << '\n';
    }
}