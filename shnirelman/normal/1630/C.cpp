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
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

//bool cmp(const pii& a, const pii& b) {
//    if()
//}

int a[N];
bool is[N];
int add[N];
int res[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> lf, rg;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        rg[a[i]] = i;
    }

    for(int i = n - 1; i >= 0; i--)
        lf[a[i]] = i;

    vector<pii> seg;
    for(auto p : lf) {
        int l = p.s;
        int r = rg[p.f];
        if(r > l) {
            seg.emplace_back(l, r);
        }
    }

    if(seg.empty()) {
        cout << 0 << endl;
        return 0;
    }

    sort(seg.begin(), seg.end());

    vector<pii> b(1, seg[0]);
    for(int i = 1; i < seg.size(); i++) {
        if(seg[i].s > b.back().s)
            b.push_back(seg[i]);
    }

    vector<pii> c;
    for(int i = 0; i < b.size(); i++) {
        while(c.size() >= 2 && c[c.size() - 2].s > b[i].f)
            c.pop_back();
        c.push_back(b[i]);
    }

    for(auto p : c) {
        add[p.f]++;
        add[p.s]--;
        is[p.f] = true;
        is[p.s] = true;
    }

//    for(int i = 0; i < c.size(); i++) {
//        cout << c[i].f << ' ' << c[i].s << endl;
//    }

    int ans = 0, cur = 0;
    for(int i = 0; i < n; i++) {
        cur += add[i];

        if(!is[i] && cur > 0)
            ans++;
    }

//    cout << ans << endl;

    for(int i = 0; i < c.size(); i++) {
        int cnt = 0;
        while(i + 1 < c.size() && c[i].s > c[i + 1].f) {
            i++;
            cnt++;
        }

        ans += cnt;
//        cout << i << ' ' << cnt << endl;
    }

    cout << ans << endl;
}