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
const int A = 1e6 + 13;
const int N = 5e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = INF64;
    for(int i = 0; i < n; i++) {
        li res = 0;
        li lst = 0;
        for(int j = i + 1; j < n; j++) {
            res += lst / a[j] + 1;
            lst = lst / a[j] * a[j] + a[j];
//            cout << "    " << j << ' ' << res << endl;
        }

//        cout << i << ' ' << res << endl;

        lst = 0;
        for(int j = i - 1; j >= 0; j--) {
            res += lst / a[j] + 1;
            lst = lst / a[j] * a[j] + a[j];
        }

//        cout << i << ' ' << res << endl;

        ans = min(ans, res);
    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}