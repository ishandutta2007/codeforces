//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
1
2 2 4
0 1000000
0 1000000
1 0
1000000 1
999999 1000000
0 999999
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    li ans = 0;
    for(int i = 0; i < n; i += 2) {
        li cur = 0;
        li mn = 0;
        for(int j = i + 1; j < n; j += 2) {
            if(a[i] < -mn)
                break;


            li x = a[i] + mn + (mn != 0);
            li cur1 = cur - mn;

            li y = max(0ll, a[j] - cur1 + (cur1 != 0));
//            if(j > i + 1) {
//                y = min(y, a[j] - a[j - 1] + 1);
//            }
            ans += min(x, y);

//            cout << i << ' ' << j << ' ' << x << ' ' << y << ' ' << cur << ' ' << mn << endl;
//            if(cur < 0)
//               ans += min(a[j] - mn + cur, a[i] + mn);

            cur -= a[j];
            mn = min(mn, cur);
            if(j + 1 < n)
                cur += a[j + 1];
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}