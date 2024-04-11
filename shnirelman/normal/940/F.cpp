#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 2e5 + 13;
const int B = 900;

/*
*/

struct Query {
    int lf, rg, tm, ind;

    Query() {};
};

bool cmp(const Query& a, const Query& b) {
    int ba = a.tm / B;
    int bb = b.tm / B;

    if(ba != bb)
        return ba < bb;
    else {
        ba = a.lf / B;
        bb = b.lf / B;

        if(ba != bb)
            return ba < bb;
        else
            return a.rg < b.rg;
    }
}

int a[N], b[N];
pair<int, pii> upd[N];
Query q[N];

int lf, rg, t;
int cnt1[A], cnt2[N];

void add(int x) {
    cnt2[cnt1[x]]--;
    cnt1[x]++;
    cnt2[cnt1[x]]++;
}

void del(int x) {
    cnt2[cnt1[x]]--;
    cnt1[x]--;
    cnt2[cnt1[x]]++;
}

void change(int ind) {
    if(lf <= upd[ind].f && upd[ind].f < rg) {
//        cout << "change "<< upd[ind].f << ' ' << upd[ind].s.f << ' ' << upd[ind].s.s << endl;
//        for(int i = 0; i < 10; i++)
//            cout << cnt2[i] << ' ';
//        cout << endl;
        del(upd[ind].s.f);
        add(upd[ind].s.s);
//        for(int i = 0; i < 10; i++)
//            cout << cnt2[i] << ' ';
//        cout << endl;

    }
    a[upd[ind].f] = upd[ind].s.s;
}

void change_back(int ind) {
    if(lf <= upd[ind].f && upd[ind].f < rg) {
        del(upd[ind].s.s);
        add(upd[ind].s.f);
    }
    a[upd[ind].f] = upd[ind].s.f;
}

int res[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;



    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    set<int> st(a, a + n);

    int qind = 0, updind = 0;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            cin >> q[qind].lf >> q[qind].rg;
            q[qind].lf--;
            q[qind].tm = updind;
            q[qind].ind = qind;
            qind++;
        } else {
            int p, x;
            cin >> p >> x;

            p--;

            upd[updind] = {p, {b[p], x}};
            b[p] = x;

            st.insert(x);

            updind++;
        }
    }

    vector<int> num(st.begin(), st.end());
    for(int i = 0; i < n; i++)
        a[i] = lower_bound(num.begin(), num.end(), a[i]) - num.begin();

//    cout << upd[0].s.f << ' ' << upd[0].s.s << endl;
    for(int i = 0; i < updind; i++) {
        upd[i].s.f = lower_bound(num.begin(), num.end(), upd[i].s.f) - num.begin();
        upd[i].s.s = lower_bound(num.begin(), num.end(), upd[i].s.s) - num.begin();
    }

//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//    cout << endl;

    sort(q, q + qind, cmp);

    cnt2[0] = INF;

    lf = 0, rg = 0;
    t = 0;
    for(int i = 0; i < qind; i++) {
        int ql = q[i].lf, qr = q[i].rg, qt = q[i].tm, qi = q[i].ind;
//        cout << qi << ' ' << ql << ' ' << qr << ' ' << qt << endl;

        while(lf > ql) {
            lf--;
            add(a[lf]);
        }

        while(rg < qr) {
            add(a[rg]);
            rg++;
        }

        while(lf < ql) {
            del(a[lf]);
            lf++;
        }

        while(rg > qr) {
            rg--;
            del(a[rg]);
        }

        while(t < qt) {
            change(t);
            t++;
        }

        while(t > qt) {
            t--;
            change_back(t);
        }

        int x = 0;
        while(cnt2[x] != 0)
            x++;

        res[qi] = x;
//        return 0;
    }

    for(int i = 0; i < qind; i++)
        cout << res[i] << '\n';
}