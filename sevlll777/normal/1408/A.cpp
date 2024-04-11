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
        vector<int> A(n), B(n), C(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        for (int i = 0; i < n; i++) cin >> C[i];
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (last != A[i] && (i == 0 || (A[i] != A[0]))) {
                cout << A[i] << ' ';
                last=  A[i];
            } else if (last != B[i] && B[i] != A[0]) {
                cout << B[i] << ' ';
                last = B[i];
            } else {
                cout << C[i] << ' ';
                last = C[i];
            }
        }
        cout << '\n';
    }

}//////