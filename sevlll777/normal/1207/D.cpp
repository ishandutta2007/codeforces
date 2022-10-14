#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#define pb push_back
#define vec vector
#define int long long
#define pii pair<int, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vec<pii> A;
    vec<pii> B;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A.pb({a, b});
        B.pb({b, a});
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vec<int> fact;
    fact.pb(1);
    for (int i = 1; i <= n; i++) {
        fact.pb((fact.back() * i) % M);
    }
    int kek1 = 1;
    int kek2 = 1;
    int kek3 = 1;
    int c1 = 1;
    int c2 = 1;
    int c3 = 1;
    for (int i = 0; i < n - 1; i++) {
        int a1 = A[i].first;
        int b1 = A[i].second;
        int a2 = A[i + 1].first;
        int b2 = A[i + 1].second;
        int a3 = B[i].second;
        int b3 = B[i].first;
        int a4 = B[i + 1].second;
        int b4 = B[i + 1].first;
        if (a1 == a2) {
            c1++;
        } else {
            kek1 *= fact[c1];
            kek1 %= M;
            c1 = 1;
        }
        if (b3 == b4) {
            c2++;
        } else {
            kek2 *= fact[c2];
            kek2 %= M;
            c2 = 1;
        }
        if (a1 == a2 && b1 == b2) {
            c3++;
        } else if (a2 >= a1 && b2 >= b1) {
            kek3 *= fact[c3];
            kek3 %= M;
            c3 = 1;
        } else {
            kek3 = 0;
        }
    }
    kek1 *= fact[c1];
    kek1 %= M;
    kek2 *= fact[c2];
    kek2 %= M;
    kek3 *= fact[c3];
    kek3 %= M;
    int bad = (M * M + kek1 + kek2 - kek3) % M;
    cout << (M * M + fact[n] - bad) % M;
}