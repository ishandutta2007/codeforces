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
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int A = 0, G = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (abs(A+a-G) <= 500) {
            A += a;
            cout << 'A';
        } else {
            G += b;
            cout << 'G';
        }
    }
    cout << '\n';
}