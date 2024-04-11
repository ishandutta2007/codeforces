//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

//#define f first
//#define s second
#define x first
#define y second
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

bool cmp(pii a, pii b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

li get(int n, int m, int k, vector<int> x, vector<int> y, vector<pii> a) {
    li res = 0;
    sort(a.begin(), a.end(), cmp);

    int cur = 0;
    for(int i = 0; i < m; i++) {
        int cnt = 0;
        map<int, int> mp;
        while(cur < k && a[cur].y < y[i]) {
            mp[a[cur].x]++;
            cnt++;
            cur++;
        }

//        cout << "get for " << i << ' ' << cnt << ' ' << cur << ' ' << k << ' ' << a[cur].y << ' ' << y[i] << endl;

        res += cnt * 1ll * (cnt - 1) / 2;

        for(auto p : mp)
            res -= p.y * 1ll * (p.y - 1) / 2;
    }

    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> x(n), y(m);
//    set<int> stx, sty;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
//        stx.insert(x[i]);
    }


    for(int j = 0; j < m; j++) {
        cin >> y[j];
//        sty.insert(y[j]);
    }


    vector<pii> a, b;
    for(int i = 0; i < k; i++) {
        int ax, ay;
        cin >> ax >> ay;
        if(*lower_bound(x.begin(), x.end(), ax) != ax)
            b.emplace_back(ay, ax);
        else if(*lower_bound(y.begin(), y.end(), ay) != ay)
            a.emplace_back(ax, ay);
    }

    li ans = 0;

    ans += get(n, m, a.size(), x, y, a);
    ans += get(m, n, b.size(), y, x, b);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}