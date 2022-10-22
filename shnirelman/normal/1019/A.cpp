//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 3000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


vector<int> g[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f;
        a[i].s--;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        g[a[i].s].push_back(i);
    }

    li ans = INF * 1ll * INF;
    for(int i = max(1, int(g[0].size())); i <= n; i++) {
//        cout << i << endl;
        vector<bool> used(n, false);
        li s = 0;
        int cnt = g[0].size();
        for(int j = 1; j < m; j++) {
            int x = max(0, int(g[j].size()) - i + 1);
//            cout << i << ' ' << j << ' ' << x << endl;
            cnt += x;
            for(int k = 0; k < x; k++) {
                s += a[g[j][k]].f;
                used[g[j][k]] = true;
            }
        }

        int j = 0;
        while(cnt < i) {
//            cout << j << endl;
            if(!used[j] && a[j].s != 0) {
                cnt++;
                s += a[j].f;
            }
            j++;
        }

//        cout << "res " << s << endl;

        ans = min(ans, s);
    }

    cout << ans << endl;
}