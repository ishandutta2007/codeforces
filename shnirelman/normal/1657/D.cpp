#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 3e5 + 13;
const int LOGN = 30;
const int A = 1e6 + 13;

/*

*/

int h[N], d[N], c[N], D[N];
li H[N], a[N], b[N];
li mx[A];
li res[A];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, C;
    cin >> n >> C;

    for(int i = 0; i < n; i++) {
        cin >> c[i] >> d[i] >> h[i];
        a[i] = d[i] * 1ll * h[i];
        mx[c[i]] = max(mx[c[i]], a[i]);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> D[i] >> H[i];
        b[i] = D[i] * H[i];
    }

    for(int i = 1; i < A; i++) {
        res[i] = max(res[i], res[i - 1]);
        for(int j = i, cur = 1; j < A; j += i, cur++) {
            res[j] = max(res[j], mx[i] * cur);
        }
    }

    for(int j = 0; j < m; j++) {
        int l = 0, r = C + 1;
        while(r - l > 1) {
            int mid = (l + r) / 2;

            if(res[mid] > b[j])
                r = mid;
            else
                l = mid;
        }

        cout << (r == C + 1 ? -1 : r) << ' ';
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}