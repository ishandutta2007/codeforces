#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int naive(int x) {
    int ma = 0;
    for (int y = 1; y <= x - 1; y++)
        ma = max(ma, (int)gcd(x ^ y, x & y));
    return ma;
}

int a[25] = {3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863};
int b[25] = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401, 22369621};

int solve(int x) {
    int k0 = -1;
    rep(k, 25) if (a[k] == x) return b[k];
    int y;
    for (y = 1; y < x; y = y * 2 + 1);
    return y;
}

int main() {
    /*
    for (int x = 2; ; x++) {
        cout << x << endl;
        if (naive(x) != solve(x)) {
            cout << "ERR" << endl;
            return 0;
        }
    }
    */
    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        cout << solve(x) << endl;
    }
}