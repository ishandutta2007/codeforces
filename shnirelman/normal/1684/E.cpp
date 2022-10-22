#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 100 + 13;
const int LOGN = 30;

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }



    auto it = mp.end();

    int cur_sum = 0;
    multiset<int> ms;
    int cnt = 0;
    bool fl = false;
    int mx = 0;

    int ans = n;
    for(int i = n; i >= 0; i--) {
        while(it != mp.begin() && prev(it)->f >= i) {
            int x = prev(it)->s;
            cur_sum += x;
            ms.insert(x);
            cnt++;

            if(cur_sum > k) {
                fl = true;
                mx = k;
                cur_sum -= *ms.rbegin();
                ms.erase(prev(ms.end()));
            }

            it--;
        }

        mx = max(mx, cur_sum);

//        if(mx + mp.size() - cnt >= i) {
        if(i - mp.size() + cnt <= k)
            ans = min(ans, cnt - int(ms.size()));
//        }

//        cout << "for " << i << ' ' << ans << endl;
    }

    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}