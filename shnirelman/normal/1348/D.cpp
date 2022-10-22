#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    int l = -1, r = INF;
    while(r - l > 1) {
        int m = (l + r) / 2;

        li sum = m;
        li x = 1;
        for(int i = 1; i <= m; i++) {

            sum += x * 1ll * (m - i + 1);
            if(sum >= n - 1) {
//                r = m;
                break;
            }
            x *= 2;
        }


//        cout << m << ' ' << sum << endl;

        if(sum < n - 1)
            l = m;
        else
            r = m;
    }

    cout << r << endl;
    n -= r;
    int cnt = 1;
    for(int i = 0; i < r; i++) {
        int lf = 0, rg = cnt + 1;
        while(rg - lf > 1) {
            int m = (lf + rg) / 2;

            if(m * 1ll * (r - i) > n - 1)
                rg = m;
            else
                lf = m;
        }

        cout << lf << ' ';
        n -= lf * 1ll * (r - i);
        cnt += lf;
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}