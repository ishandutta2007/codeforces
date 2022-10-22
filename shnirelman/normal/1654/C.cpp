//#define _GLIBCXX_DEBUG
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
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;



/*
1
1
327
*/



//void calc(li x) {
//    if(x < INF && mp.count(x)) {
//        mp[x]--;
//        if(mp[x] == 0)
//            mp.erase(x);
//        return;
//    }
//
//    if(x <= 1)
//        return;
//
//    calc(x / 2);
//    calc((x + 1) / 2);
//}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        sum += a[i];
        mp[a[i]]++;
    }


    map<li, int> cur;
    cur[sum] = 1;

    while(!cur.empty()) {
        li x = cur.rbegin()->f;
        int cnt = cur.rbegin()->s;

        if(mp.rbegin()->f > x || mp[x] > cnt) {
            cout << "NO\n";
            return;
        }

        cnt -= mp[x];
        mp[x] = 0;

        mp.erase(x);
        cur.erase(x);

        if(cnt) {
            cur[x / 2] += cnt;
            cur[(x + 1) / 2] += cnt;
        }
    }

    cout << "YES\n";
//
//    cout << (mp.empty() ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}