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
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k % 2 == 0 && n % 2 == 1) {
            cout << "NO\n";
        } else {
            if (n % 2 == 0) {
                if ((n - (k - 1)) % 2 == 1) {
                    if (n < k) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                        for (int i = 0; i < k - 1; i++) cout << "1 ";
                        cout << (n - k + 1) << '\n';
                    }
                } else {
                    if (2 * k > n) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                        for (int i = 0; i < k - 1; i++) cout << "2 ";
                        cout << n - 2 * (k - 1) << '\n';
                    }
                }
            } else {
                if (n < k) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    for (int i = 0; i < k - 1; i++) cout << "1 ";
                    cout << n - (k - 1) << '\n';
                }
            }
        }
    }

}