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
const int M = 998244353;

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
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> P(n);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            int me = A[i] + P[i - 1] - A[i - 1];
            P[i] = max(P[i - 1], me);
            if (P[i] > A[i]) ok = false;
        }
        if (ok) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

}