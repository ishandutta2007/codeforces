#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    k++;
    k /= 2;
    for (; k; --k) {
//        cerr << n << endl;
        ll x = n;
        for (ll i = 2; i * i <= n; ++i) {
            if (n % i) {
                continue;
            }
            x /= i;
            x *= i - 1;
            while (n % i == 0) {
                n /= i;
            }
        }
        if (n > 1) {
            x /= n;
            x *= n - 1;
        }
        n = x;
        if (n == 1) {
            break;
        }
    }
    cout << n % 1000000007 << endl;
    return 0;
}