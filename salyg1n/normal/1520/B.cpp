#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= 9; ++i) {
            ll c = i;
            while (c <= n) {
                ans++;
                c *= 10;
                c += i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}