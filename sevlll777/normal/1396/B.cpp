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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            s += A[i];
        }
        sort(A.begin(), A.end());
        if (n == 1) {
            cout << "T\n";
        } else if (n == 2) {
            if (A[0] == A[1]) {
                cout << "HL\n";
            } else {
                cout << "T\n";
            }
        } else {
            int m = A.back();
            if (s % 2) {
                cout << "T\n";
            } else {
                int f = s / 2;
                if (f >= m) {
                    cout << "HL\n";
                } else {
                    cout << "T\n";
                }
            }
        }

    }

}