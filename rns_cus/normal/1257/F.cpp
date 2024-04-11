#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, a[N];

map <vector <int>, int> mp;

int solve() {
    for (int i = 1; i < n; i ++) a[i] ^= a[0];
    int m = 1 << 15;
    for (int i = 0; i < m; i ++) {
        vector <int> v;
        for (int j = 1; j < n; j ++) {
            int c = __builtin_popcount(a[j]);
            if (c & 1) return -1;
            v.push_back(c / 2 - __builtin_popcount(i & a[j]));
        }
        mp[v] = i;
    }
    for (int i = 0; i < m; i ++) {
        vector <int> v;
        for (int j = 1; j < n; j ++) v.push_back(__builtin_popcount(a[j] >> 15 & i));
        auto it = mp.find(v);
        if (it != mp.end()) return (i << 15 | it -> second) ^ a[0];
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    printf("%d\n", solve());
//    int x = solve(); if (x < 0) return 0; cout << x << endl;
//    for (int i = 1; i < n; i ++) a[i] ^= a[0];
//    for (int i = 1; i < n; i ++) assert(__builtin_popcount(x ^ a[i]) == __builtin_popcount(x ^ a[0]));

    return 0;
}