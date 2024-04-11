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
    int n;
    cin >> n;
    if (n == 1) {
        int a;
        cin >> a;
        cout << "1 1\n" << -a << '\n';
        cout << "1 1\n0\n1 1\n0\n";
        exit(0);
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i] = -A[i];
    }
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        int x = 1 - (n - A[i]);
        cout << x * n << ' ';
        if (i == 0) A[0] -= x * n;
    }
    cout << '\n';
    cout << 2 << ' ' << n << '\n';
    for (int i = 1; i < n; i++) {
        int y = n - A[i];
        cout << y * (n - 1) << ' ';
    }
    cout << '\n';

    cout << "1 1\n" << A[0] << '\n';

}