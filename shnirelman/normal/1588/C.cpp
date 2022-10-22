//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
1
2
2 2

1
4
1 1 1 1

1
4
1 2 2 1
*/

int a[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = 0;

    map<li, int> mp;
    li add = 0;
//    mp[0] = 1;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            while(!mp.empty() && mp.begin()->f + add + a[i] < 0)
                mp.erase(mp.begin());



//            add -= a[i];

            add += a[i];
            mp[a[i] - add]++;


            ans += mp[-add];
        } else {
            auto it = mp.end();
            while(!mp.empty() && (--it)->f + add > a[i]) {
                mp.erase(it);
                it = mp.end();
            }

//            add += a[i];
            add -= a[i];

            mp[-a[i]-add]++;

            ans += mp[-add];
        }

//        cout << ans << endl;
//        for(auto p : mp) {
//            cout << p.f + add << ' ' << p.f << ' ' << p.s << endl;
//        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}