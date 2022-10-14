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
        int n;
        cin >> n;
        int l = 0;
        int r = n - 1;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        int s = 0;
        int a = 0, b = 0;
        int c = 0;
        while (l <= r) {
            int kekw = 0;
            if (c % 2 == 0) {
                while (l <= r && kekw <= s) {
                    kekw += A[l++];
                }
                a += kekw;
                s = kekw;
            } else {
                while (l <= r && kekw <= s) {
                    kekw += A[r--];
                }
                b += kekw;
                s = kekw;
            }
            c++;
        }
        cout << c << ' ' << a << ' ' << b << '\n';
    }

}