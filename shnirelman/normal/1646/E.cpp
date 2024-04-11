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

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int LOGN = 21;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

bool used[N];
li res[LOGN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;



    li ans = 1;
    for(int i = 2; i <= n; i++) if(!used[i]) {
        int cnt = 0;
        li x = i;
        while(x <= n) {
            used[x] = true;
            cnt++;
            x *= i;
        }

        if(res[cnt] == 0) {
            for(int i = 1; i <= cnt; i++) {
                for(int k = 1; k <= m; k++) {
                    int x = k * i;
                    bool rs = true;
                    for(int j = 1; j < i; j++) {
                        if(x % j == 0 && x / j <= m) {
                            rs = false;
                            break;
                        }
                    }

//                    cout << "calc " << cnt << " - " << i << ' ' << k << ' ' << rs << endl;

                    res[cnt] += rs;
                }
            }
        }

//        cout << i << ' ' << cnt << ' ' << res[cnt] << endl;

        ans += res[cnt];
    }

    cout << ans << endl;
}