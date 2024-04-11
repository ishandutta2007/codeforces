#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
1
2
1 7

1
3
1 5 4
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<bool> is(n + 1, false);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= n && !is[a[i]])
            is[a[i]] = true;
        else
            mp[a[i]]++;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int x = (!mp.empty() ? mp.begin()->f : INF);
//        cout << i << ' ' << x << ' ' << ans << ' ' << is[i] << endl;
        if(!is[i] && x != i && x <= i * 2 + 2) {
            if(x != i && x <= i * 2) {
                cout << -1 << endl;
                return;
            }
            mp[x]--;
            if(mp[x] == 0)
                mp.erase(x);
//            if(x <= n)
//                is[x] = false;

            ans += (x != i);
        } else {
            if(!is[i]) {
                ans++;
                mp[x]--;
                if(mp[x] == 0)
                    mp.erase(x);
            }
        }
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