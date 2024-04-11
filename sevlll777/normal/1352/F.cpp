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
// #define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        int x0 = n0, x1 = n1, x2 = n2;
        if (n1 == 0) {
            string ans = "";
            if (n0) n0++;
            if (n2) n2++;
            while (n0--) ans += '0';
            while (n2--) ans += '1';
            cout << ans + '\n';
        } else {
            string ans = "0";
            while (n0--) ans += '0';
            while (n1--) ans += '1' + '0' - ans.back();
            if (n2 == 0) {
                cout << ans << '\n';
            } else {
                if (ans.back() == '1') {
                    while (n2--) ans += '1';
                    cout << ans+'\n';
                } else {
                    if (x1 > 1) {
                        string ans = "10";
                        while (x0--) ans += '0';
                        ans += '1'; x1--;x1--;
                        while (x1--) ans += '1'+'0'-ans.back();
                        while (x2--) ans += '1';
                        cout << ans << '\n';
                    } else {
                        cout << "-1\n";
                    }
                }
            }
        }
    }

}