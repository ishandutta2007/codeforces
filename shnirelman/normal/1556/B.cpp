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
    int cnt = 0;
    int res0 = 0, res1 = 0;
    int cur0 = 0, cur1 = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(a[i] % 2 == 0) {
            cnt++;
            res0 += abs(cur0 - i);
            res1 += abs(cur1 - i);

            cur0 += 2;
            cur1 += 2;
        }
    }

    int ans = -1;
    if(n / 2 == cnt) {
        if(n % 2 == 0)
            ans = min(res0, res1);
        else
            ans = res1;
    } else if(cnt * 2 - 1 == n) {
        ans = res0;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}