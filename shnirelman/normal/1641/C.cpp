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

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int mn[N * 4];

void update(int v, int l, int r, int ql, int qr, int x) {
    if(ql >= r || qr <= l || mn[v] < x)
        return;

    if(ql <= l && r <= qr) {
        mn[v] = x;
        return;
    }

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);
}

int get(int v, int l, int r, int qi) {
    if(r - l == 1)
        return mn[v];

    int m = (l + r) / 2;

    if(qi < m)
        return min(mn[v], get(v * 2 + 1, l, m, qi));
    else
        return min(mn[v], get(v * 2 + 2, m, r, qi));
}


int t[N * 4];
bool fl[N * 4];

void update(int v, int l, int r, int ql, int qr) {
    if(ql >= r || qr <= l || fl[v])
        return;

//    cout << "update " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << t[v] << endl;

    if(ql <= l && r <= qr) {
        t[v] = r - l;
        fl[v] = true;
        return;
    }

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr);
    update(v * 2 + 2, m, r, ql, qr);

    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

void push(int v, int l, int m, int r) {
    t[v * 2 + 1] = m - l;
    t[v * 2 + 2] = r - m;
    fl[v * 2 + 1] = true;
    fl[v * 2 + 2] = true;
    fl[v] = false;
}

int get(int v, int l, int r, int ql, int qr) {
    if(ql >= r || qr <= l)
        return 0;



    if(ql <= l && r <= qr) {
//        cout << "return " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << t[v] << endl;
        return t[v];
    }

    int m = (l + r) / 2;
    if(fl[v])
        push(v, l, m, r);



    return get(v * 2 + 1, l, m, ql, qr) + get(v * 2 + 2, m, r, ql, qr);
}

int n, q;
int m0, m1;
int q0l[N], q0r[N], q1l[N], q1r[N];
int t0[N], t1[N];

int mq;
pii query[N];

void clr() {
    for(int i = 0; i < N * 4; i++) {
        t[i] = 0;
        fl[i] = false;
    }
}

vector<bool> is(vector<pii> x) {
    sort(x.begin(), x.end());
    int j = 0;
    clr();
    vector<bool> res(m1, false);
    for(int i = 0; i <= m0; i++) {
        while(j < m1 && x[j].f <= i) {
//            cout << i << ' ' << j << ' ' << get(0, 0, n, q1l[x[j].s], q1r[x[j].s]) << ' ' << q1r[x[j].s] - q1l[x[j].s] << endl;
            if(get(0, 0, n, q1l[x[j].s], q1r[x[j].s]) == q1r[x[j].s] - q1l[x[j].s] - 1) {
                res[x[j].s] = true;
            }
            j++;
        }

        if(i < m0) {
//            cout << q0l[i] << ' ' << q0r[i] << endl;
            update(0, 0, n, q0l[i], q0r[i]);
        }
    }

    return res;
}

/*
3 3
0 1 2 1
1 1
0 2 2 0

3 3
0 1 2 1
0 2 2 0
1 1


3 2
1 1
0 1 1 1
*/

int ans[N];
int when[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> q;

    for(int i = 0; i < N * 4; i++) {
        mn[i] = INF;
    }

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 0) {
            int l, r, x;
            cin >> l >> r >> x;

            l--;

            if(x == 0) {
                q0l[m0] = l;
                q0r[m0] = r;
                t0[m0] = i;
                m0++;

                update(0, 0, n, l, r, i);
            } else {
                q1l[m1] = l;
                q1r[m1] = r;
                t1[m1] = i;
                m1++;
            }
        } else {
            cin >> query[mq].f;
            query[mq].f--;
            query[mq].s = i;
            mq++;
        }
    }

    for(int i = 0; i < n; i++)
        when[i] = INF;

    for(int i = 0; i < n; i++) {
        int rs = get(0, 0, n, i);
        if(rs < INF) {
            ans[i] = -1;
            when[i] = rs;
        }
    }

    vector<int> l(m1, -1), r(m1, m0 + 1);
    for(int ind = 0; ind < 20; ind++) {
        vector<pii> x(m1);
        for(int i = 0; i < m1; i++) {
            x[i].s = i;
            x[i].f = (l[i] + r[i]) / 2;

//            cout << "binary search " << ind << ' ' << i << ' ' << x[i].f << ' ' << l[i] << ' ' << r[i] << endl;
        }

        vector<bool> rs = is(x);

        for(int i = 0; i < m1; i++) {
            if(rs[i])
                r[i] = x[i].f;
            else
                l[i] = x[i].f;
        }
    }

    for(int i = 0; i < m1; i++) {
        if(r[i] <= m0 && r[i] > 0) {
            t1[i] = max(t1[i], t0[l[i]]);
        }
    }

//    for(int i = 0; i < m1; i++) {
//        cout << "qr 1 -- " << l[i] << ' ' << r[i] << endl;
//    }

    for(int i = 0; i < m1; i++) if(r[i] < m0 + 1) {
        int lf = q1l[i], rg = q1r[i];
        while(rg - lf > 1) {
            int m = (lf + rg) / 2;

            if(get(0, 0, n, q1l[i], m) < m - q1l[i])
                rg = m;
            else
                lf = m;
        }

        ans[lf] = 1;
        when[lf] = min(when[lf], t1[i]);
    }

//    for(int i = 0; i < n; i++) {
//        cout << i << " : " << ans[i] << ' ' << when[i] << endl;
//    }

    for(int i = 0; i < mq; i++) {
        if(when[query[i].f] < query[i].s)
            cout << (ans[query[i].f] == 1 ? "YES\n" : "NO\n");
        else
            cout << "N/A\n";
    }
}