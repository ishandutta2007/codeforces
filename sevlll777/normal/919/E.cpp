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
int p;

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2) {
            ans *= a;
            ans %= p;
        }
        a *= a;
        a %= p;
        x /= 2;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, x;
    cin >> a >> b >> p >> x;
    int ans = (p - 1) * (x / (p * (p - 1)));
    x %= (p * (p - 1));
    for (int r2 = 0; r2 < p - 1; r2++) {
        int r1 = (b * binpow(a, (r2 * (p - 2)) % (p - 1))) % p;
        int d = (p + r2 - r1) % p;
        if (x >= (p - 1) * d) {
            int kek = x - (p - 1) * d;
            if (kek >= r2) {
                ans++;
            }
        }
    }
    if (b == 0) ans--;
    cout << ans << '\n';

}