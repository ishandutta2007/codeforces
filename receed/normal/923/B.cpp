#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    multiset<ll> s;
    ll t, d = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ll ans = 0;
        s.insert(v[i] + d);
        while (!s.empty() && *s.begin() - d <= t) {
            ans += *s.begin() - d;
            s.erase(s.begin());
        }
        ans += (ll) s.size() * t;
        d += t;
        cout << ans << ' ';
    }

}