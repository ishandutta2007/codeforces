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
    string s, t;
    cin >> s >> t;
    map<char, int> ss, tt;
    for (auto c : s) ss[c]++;
    for (auto c : t) tt[c]++;
    int ura = 0, opa = 0;
    for (auto c : t) {
        int m = min(tt[c], ss[c]);
        tt[c] -= m;
        ss[c] -= m;
        ura += m;
    }
    char c1 = 'a', c2 = 'A';
    for (int _ = 0; _ < 26; _++) {
        if (ss[c1] && tt[c2]) {
            int m = min(ss[c1], tt[c2]);
            ss[c1] -= m;
            tt[c2] -= m;
            opa += m;
        }
        if (ss[c2] && tt[c1]) {
            int m = min(ss[c2], tt[c1]);
            ss[c2] -= m;
            tt[c1] -= m;
            opa += m;
        }
        c1++; c2++;
    }
    cout << ura << ' ' << opa << '\n';



}