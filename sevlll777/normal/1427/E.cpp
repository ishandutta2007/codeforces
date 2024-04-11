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
    int x;
    cin >> x;
    vector<tuple<int, char, int>> A;
    while (x != 1) {
        int bit = (int) ceil(log2(x + 1));
        int now = x;
        for (int _ = 0; _ < bit - 1; _++) {
            A.pb({now, '+', now});
            now += now;
        }
        int chel = now;
        A.pb({now, '+', x});
        A.pb({now, '^', x});
        int l1 = now + x, l2 = now ^x;
        A.pb({l1, '+', l2});
        int h = l1 + l2;
        A.pb({now, '+', now});
        now += now;
        A.pb({now, '^', h});
        now ^= h;
        A.pb({now, '^', x + x});
        now ^= (x + x);
        while (now + now <= 1e12) {
            A.pb({now, '+', now});
            now += now;
        }
        for (int i = 50; i >= bit; i--) {
            if ((chel >> i) & 1) {
                A.pb({chel, '^', (1LL << i)});
                chel ^= (1LL << i);
            }
        }
        A.pb({x, '^', chel});
        x ^= chel;
    }
    cout << A.size() << '\n';
    for (auto c : A) {
        cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << '\n';
    }
}