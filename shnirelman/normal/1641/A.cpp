#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void NO() {
    cout << "NO" << endl;
    exit(0);
}

void solve() {
    int n, x;
    cin >> n >> x;

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;
        mp[y]++;
    }

    int ans = 0;
    while(!mp.empty()) {
        vector<int> b;
        for(li y = mp.begin()->f; y < INF && mp.count(y); y *= x) {
            b.push_back(mp[y]);
            mp.erase(y);
        }

        int cur = 0;
        for(int i = 0; i < b.size(); i++) {
            int d = min(cur, b[i]);

            cur -= d;
            b[i] -= d;

            ans += cur;
            cur = b[i];
        }

        ans += cur;

//        for(int y = mp.begin()->f; y * 1ll * x < INF && mp.count(y); y *= x) {
//
//        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}