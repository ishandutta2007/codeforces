#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 998244353;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    long long ans = 0;
    long long x = 1;
    forn (i, n - 1) {
        x *= n - i;
        x %= mod;
        ans -= x;
        ans += mod;
        ans %= mod;
    }
    ans += x * n;
    ans %= mod;
    cout << ans << endl;
    return 0;
}