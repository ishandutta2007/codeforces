// #define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int m;
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];
    int ans = 0;
    int u1 = 0, u2 = 0;
    int s1 = 0, s2 = 0;
    while (u1 < n || u2 < m) {
        if (u1 == n) {
            s2 += B[u2++];
        } else if (u2 == m) {
            s1 += A[u1++];
        } else if (s1 < s2) {
            s1 += A[u1++];
        } else {
            s2 += B[u2++];
        }
        if (s1 == s2) {
            ans++;
            s1 = 0;
            s2 = 0;
        }
    }
    if (ans == 0 || s1 != s2) {
        ans = -1;
    }
    cout << min({n, m, ans});



}