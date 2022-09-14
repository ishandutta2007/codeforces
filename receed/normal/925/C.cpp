#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
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
    int n, p = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    deque<ll> ans, t;
    for (int i = 59; i >= 0; i--) {
        t = ans;
        ans.clear();
        ll cx = 0;
        while (p < n && a[p] & (1ll << i)) {
            while (cx && !t.empty()) {
                cx ^= t.front() & (1ll << i);
                ans.push_back(t.front());
                t.pop_front();
            }
            if (cx) {
                cout << "No";
                return 0;
            }
            cx ^= 1ll << i;
            ans.push_back(a[p]);
            p++;
        }
        for (ll w : t)
            ans.push_back(w);

    }
    cout << "Yes\n";
    ll r = 0;
    for (ll w : ans) {
        cout << w << ' ';
        //r ^= w;
        //cout << r << '\n';
    }
}