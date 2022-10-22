#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 12;
const int M = 1e9 + 7;
const int B = 600;
const int K = 103;

/*
*/

int w[N];
int cnt[1 << N];
int res[1 << N][K];


void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++)
        cin >> w[i];

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        int x = 0;
        for(int j = 0; j < n; j++)
            x = x * 2 + (s[j] - '0');

//        cout << x << endl;

        cnt[x]++;
    }

    for(int x = 0; x < (1 << n); x++) {
        for(int y = 0; y < (1 << n); y++) {
            int rs = 0;
            for(int i = 0; i < n; i++)
                if(((x >> i) & 1) == ((y >> i) & 1))
                    rs += w[n - i - 1];
//            cout << x << ' ' << y << ' ' << rs << endl;
            if(rs < K)
                res[x][rs] += cnt[y];
        }
    }

    for(int i = 0; i < q; i++) {
        string s;
        int k;
        cin >> s >> k;

        int x = 0;
        for(int j = 0; j < n; j++)
            x = x * 2 + (s[j] - '0');

        int ans = 0;
        for(int j = 0; j <= k; j++)
            ans += res[x][j];
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}