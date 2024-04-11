#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> d;

void init() {
    vector <int> f(MAXN, -1);
    vector <int> p;
    d.resize(MAXN, 0);
    for (int i = 2; i < MAXN; i++) {
        if (f[i] == -1) {
            f[i] = p.size();
            p.push_back(i);
        }
        for (int j = 0; j <= f[i]; j++) {
            if (p[j] * i >= MAXN) break;
            f[p[j] * i] = j;
        }
    }
    d[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        int x = p[f[i]];
        int y = i;
        int st = 0;
        while (y % x == 0) {
            st++;
            y /= x;
        }
        d[i] = d[y] * (st + 1);
    }
}

const int SQ = 550;

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
    init();
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    vector <ll> sums;
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        cnt++;
        if (cnt == SQ) {
            sums.push_back(sum);
            sum = 0;
            cnt = 0;
        }
    }
    if (sum) {
        sums.push_back(sum);
    }
    set <int> q;
    for (int i = 0; i < n; i++) {
        if (a[i] > 2) {
            q.insert(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            vector <int> e;
            auto it = q.lower_bound(l);
            while (it != q.end() && *it <= r) {
                int pos = *it;
                sums[pos / SQ] -= a[pos];
                a[pos] = d[a[pos]];
                sums[pos / SQ] += a[pos];
                if (a[pos] <= 2) {
                    e.push_back(pos);
                }
                it++;
            }
            for (int x : e) {
                q.erase(x);
            }
        } else {
            ll res = 0;
            while (l % SQ && l <= r) {
                res += a[l];
                l++;
            }
            while (l + SQ - 1<= r) {
                res += sums[l / SQ];
                l += SQ;
            }
            while (l <= r) {
                res += a[l];
                l++;
            }
            cout << res << "\n";
        }
    }
}