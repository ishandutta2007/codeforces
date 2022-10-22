#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);

vector<int> d[N];

void solve() {
    int l, r;
    cin >> l >> r;

    li ans = (r - l + 1) * 1ll * (r - l) * (r - l - 1) / 6;
    for(int i = l + 2; i <= r; i++) {
        int cnt = d[i].size() - (lower_bound(d[i].begin(), d[i].end(), l) - d[i].begin());
        ans -= /*(i - l) * 1ll * (i - l - 1) / 2 -*/ cnt * 1ll * (cnt - 1) / 2;
        //int rs = (i - l) * 1ll * (i - l - 1) / 2 - cnt * 1ll * (cnt - 1) / 2;
        if(i % 3 == 0) {
            if(i / 3 * 2 >= l && i % 2 == 0 && i / 2 >= l)
                ans--/*, rs--*/;
            if(i / 3 * 2 >= l && i % 5 == 0 && i / 5 * 2 >= l)
                ans--/*, rs--*/;
        }


//        int res = 0;
//        for(int x = l; x < i; x++) {
//            for(int y = x + 1; y < i; y++) {
//                li lcm = x * 1ll * y / __gcd(x, y);
//                lcm = lcm * i / __gcd(lcm, i * 1ll);
//
//                if(lcm >= i + x + y) {
//                    res++;
////                    cout << x << ' ' << y << ' ' << i << endl;
//                } else {
//                    cout << x << ' ' << y << ' ' << i << endl;
//                }
//
//            }
//        }
//
//        if(res != rs) {
//            cout << "asgf" << endl;
//            cout << i << ' ' << rs << ' ' << res << ' ' << cnt << endl;
//            return ;
//        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        for(int j = i + i; j < N; j += i)
            d[j].push_back(i);
    }

//    for(int i = 1; i < 30; i++) {
//        cout << i << " : ";
//        for(int x : d[i])
//            cout << x << ' ';
//        cout << endl;
//    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}