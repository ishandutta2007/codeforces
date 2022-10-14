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
#define str string
using namespace std;
const int M = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        bool vis1 = false, visn = false;
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (A[i] < B[i]) {
                if (!vis1) {
                    ans = "NO";
                    break;
                }
            } else if (A[i] > B[i]) {
                if (!visn) {
                    ans = "NO";
                    break;
                }
            }

            if (A[i] > 0) vis1 = true;
            if (A[i] < 0) visn = true;
        }
        cout << ans << '\n';

    }
}