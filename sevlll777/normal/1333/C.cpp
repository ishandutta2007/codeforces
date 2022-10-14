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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<int> P(n + 1);
    for (int i = 0; i < n; i++) P[i + 1] = P[i] + A[i];
    map<int, vector<int>> inds;
    for (int i = 0; i <= n; i++) {
        inds[P[i]].pb(i);
    }
    vector<int> lol(n+1);
    lol[n] = 1;
    int ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = n - i + 1;
        if (inds[P[i]].back() != i) {
            num = *upper_bound(inds[P[i]].begin(), inds[P[i]].end(), i) - i;
        }
        lol[i] = min(lol[i+1]+1, num);
        ans += lol[i];
    }
    cout << ans-n-1;
}