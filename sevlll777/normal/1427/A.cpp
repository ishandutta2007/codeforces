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
        if (s == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (s > 0) {
            for (int i = 0; i < n; i++) {
                if (A[i] > 0) cout << A[i] << ' ';
            }
            for (int i = 0; i < n; i++) {
                if (A[i] < 0) cout << A[i] << ' ';
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (A[i] < 0) cout << A[i] << ' ';
            }
            for (int i = 0; i < n; i++) {
                if (A[i] > 0) cout << A[i] << ' ';
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) cout << A[i] << ' ';
        }
        cout << '\n';
    }
}