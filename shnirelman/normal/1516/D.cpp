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
const int N = 1e5 + 113;
const int LOGN = 20;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

mt19937 rnd(3666);

int a[N];

int d[N];

int nxt[N][LOGN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            d[i] = i;

            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> lst;

    for(int i = 0; i < LOGN; i++)
        nxt[n][i] = n;

    for(int i = n - 1; i >= 0; i--) {
        int x = a[i];
        nxt[i][0] = nxt[i + 1][0];

        while(x > 1) {
            if(lst.count(d[x]) && lst[d[x]] > i)
                nxt[i][0] = min(nxt[i][0], lst[d[x]]);
            lst[d[x]] = i;
            x /= d[x];
        }

        for(int j = 1; j < LOGN; j++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
//
//        cout << i << " : " << nxt[i][0] << ' ' << nxt[i][1] << ' ' << nxt[i][2] << endl;
//        cout << "lst : " << lst[2] << ' ' << lst[3] << endl;
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        int res = 1;
        for(int k = LOGN - 1; k >= 0; k--) {
            if(nxt[l][k] < r) {
                res += (1 << k);
                l = nxt[l][k];
            }
        }

        cout << res << '\n';
    }
}