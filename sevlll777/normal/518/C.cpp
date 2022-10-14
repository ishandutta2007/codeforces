#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> index(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        index[x] = i;
        a[i] = x;
    }
    int ans = 0;
    while (m--) {
        int x;
        cin >> x;
        x--;
        ans += 1+index[x] / k;
        if (index[x] != 0) {
            int pered = a[index[x] - 1];
            int ind = index[x];
            index[pered] = ind;
            index[x] = ind - 1;
            a[ind] = pered;
            a[ind - 1] = x;
        }
        // cout << ans << '\n';

    }
    cout << ans;


}