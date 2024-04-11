#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

map<ll, int> m;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    ll s = 0;
    ll ans = 0;
    forn (i, n) {
        m[s]++;
        int x;
        cin >> x;
        s += x;
        ll p = 1;
        while (abs(p) <= 100000000000000ll) {
            ans += m[s - p];
            p *= k;
            if (p == 1) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}