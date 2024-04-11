#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n;

struct Tree {
    vector <ll> t;
    Tree(int n) : t(8 * n, 0) {}
    void change(int v, ll x, int lt = 0, int rt = n, int vt = 1) {
        if (lt > v || rt <= v) return;
        if (rt - lt == 1) {
            t[vt] = x;
            return;
        }
        ll mt = (lt + rt) / 2;
        change(v, x, lt, mt, 2 * vt);
        change(v, x, mt, rt, 2 * vt + 1);
        t[vt] = t[2 * vt] + t[2 * vt + 1];
    }
    ll get(int l, int r, int lt = 0, int rt = n, int vt = 1) {
        if (l >= rt || lt >= r) {
            return 0;
        }
        if (l <= lt && rt <= r) {
            //cout << lt << " " << rt << " " << vt << " " << t[vt] << "\n";
            return t[vt];
        }
        int mt = (lt + rt) / 2;
        return get(l, r, lt, mt, 2 * vt) + get(l, r, mt, rt, 2 * vt + 1);
    }
    ll force(ll sum, int lt = 0, int rt = n, int vt = 1) {
        int mt = (lt + rt) / 2;
        if (rt - lt == 1) {
            return lt;
        }
        if (t[2 * vt] > sum) {
            return force(sum, lt, mt, 2 * vt);
        }
        sum -= t[2 * vt];
        return force(sum, mt, rt, 2 * vt + 1);
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll all;
    cin >> n >> all;
    Tree t(n), ex(n);
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        t.change(i, a[i]);
        ex.change(i, 1);
    }
    //cout << "KEK " << t.get(1, 2) << "\n";
    ll pos = 0;
    ll cnt = n;
    ll res = 0;
    while (cnt) {
        ll sum = t.get(0, n);
       // cout << "SUM " << sum << "\n";
        res += cnt * (all / sum);
        all = all % sum;
        ll pref = t.get(pos, n);
        if (pref > all) {
            all += t.get(0, pos);
            res -= ex.get(0, pos);
        } else {
            all -= pref;
            res += ex.get(pos, n);
        }
       // cout << all << " " << res << " " << pos << "\n";
        ll now = t.force(all);
        all -= t.get(0, now);
        //cout << t.get(0, 2) << " " << now << " " << all << "\n";
        res += ex.get(0, now);
        t.change(now, 0);
        ex.change(now, 0);
        pos = now;
        cnt--;
    }
    cout << res;
}