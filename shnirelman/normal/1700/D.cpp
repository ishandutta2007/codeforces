#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    li sum = 0;
    li mn = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mn = max(mn, (sum + i) / (i + 1));
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        li res = (sum + t - 1) / t;

//        if(res <= n)
        if(t >= mn)
            cout << res << '\n';
        else
            cout << "-1\n";
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}