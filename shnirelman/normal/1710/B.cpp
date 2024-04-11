#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

/*
*/

void solve() {
    li n, m;
    cin >> n >> m;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    map<int, li> res;

//    vector<pii> b;
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i].f - a[i].s].push_back(i);
        mp[a[i].f].push_back(i);
        mp[a[i].f + a[i].s].push_back(i);
    }

//    sort(b.begin(), b.end());

    li cur = 0;
    li add = 0;
    for(auto p : mp) {
        for(int i : p.s) {
            if(a[i].f - a[i].s == p.f) {
                add++;
                cur -= p.f;
            } else if(a[i].f == p.f) {
                add -= 2;
                cur += a[i].f - a[i].s;
                cur += a[i].s + a[i].f;
            } else {
                add++;
                cur -= a[i].s + a[i].f;
            }
        }

        res[p.f] = cur + add * p.f;
    }

//    for(auto p : res)
//        cout << p.f << ' ' << p.s << endl;

    vector<pair<li, li>> b;
    for(auto p : res) {
        if(p.s > m)
            b.push_back(p);
    }

    if(b.empty()) {
        for(int i = 0; i < n; i++)
            cout << 1;
        cout << endl;
        return;
    }

    vector<pair<pii, int>> c(n);
    for(int i = 0; i < n; i++) {
        c[i] = {a[i], i};
    }

    sort(c.begin(), c.end());

    vector<bool> ans(n, false);
    set<pair<li, int>> st;
    for(int i = 0; i < b.size(); i++) {
        st.emplace(b[i].f + b[i].s - m, i);
    }

//    return;
    li mx = -INF64;
    for(int i = 0, k = 0; i < n; i++) {
        int j = c[i].s;
//        cout << i << " -- " << a[j].f << endl;
        while(k < b.size() && b[k].f < a[j].f) {
            mx = max(mx, b[k].s - m - b[k].f);
            st.erase({b[k].f + b[k].s - m, k});
            k++;
        }
//        while(!st.empty() && st.begin()->f < a[j].f) {
//            mx = max(mx, st.begin()->)
//        }
        if(a[j].f - a[j].s >= b[0].f || a[j].f + a[j].s <= b.back().f) {

        } else {
            if(a[j].f - a[j].s + mx <= 0 && (st.empty() || st.rbegin()->f - a[j].f - a[j].s <= 0))
                ans[j] = true;
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}