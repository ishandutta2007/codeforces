#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/

int a[N], b[N];

void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int j = 0; j < m; j++)
        cin >> b[j];

    int mni = -1, mnj = -1;
    for(int i = 0; i < n; i++)
        if(a[i] % p != 0) {
            mni = i;
            break;
        }

    for(int i = 0; i < m; i++)
        if(b[i] % p != 0) {
            mnj = i;
            break;
        }

    cout << mni + mnj  << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}