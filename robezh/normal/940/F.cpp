#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, E6 = (int)1e6 + 50, BK = 2150, SQRT = 500;

int n, m;

struct qr {
    int l, r, id;

    void set(int _l, int _r, int _id) {
        l = _l, r = _r, id = _id;
    }
} qrs[N];

int qsz = 0;

struct modi {
    int i, x, id;

    void set(int _i, int _col, int _id) {
        i = _i, x = _col, id = _id;
    }
}ms[N];
int msz = 0;

bool cmp(const qr &q1, const qr &q2) {
    if(q1.l / BK != q2.l / BK) return q1.l < q2.l;
    if(q1.r / BK != q2.r / BK) return q1.r < q2.r;
    return q1.id < q2.id;
}

int tcnt = 0;
int cnt[N], ocnt[N];
int a[N];
int res[N];

int num[N];

int get_mex() {
    for(int i = 1; i < SQRT; i++) {
        if(ocnt[i] == 0) return i;
    }
    return 1;
}

void extend(int i, int val) {
    ocnt[cnt[i]] -= 1;
    cnt[i] += val;
    ocnt[cnt[i]] += 1;
}

int ql = 0, qr = -1, qt = -1;



void change(modi &m, int val) {
//    extend(m.col, val);
    if(ql <= m.i && m.i <= qr) extend(num[m.i], -1);
    swap(m.x, num[m.i]);
    if(ql <= m.i && m.i <= qr) extend(num[m.i], 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        a[i] = num[i];
    }
    int alen = n;

    fill(res, res + m, -1);
    for(int i = 0; i < m; i++) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int l, r;
            cin >> l >> r; l--, r--;
            qrs[qsz++].set(l, r, i);
        }
        else {
            int loc, x;
            cin >> loc >> x; loc--;
            ms[msz++].set(loc, x, i);
            a[alen++] = x;
        }
    }
    sort(a, a + alen);
    alen = (int)(unique(a, a + alen) - a);
    for(int i = 0; i < n; i++) num[i] = (int)(lower_bound(a, a + alen, num[i]) - a);
    for(int i = 0; i < msz; i++) ms[i].x = (int)(lower_bound(a, a + alen, ms[i].x) - a);
    sort(qrs, qrs + qsz, cmp);
    for(int i = 0; i < qsz; i++) {
        while(ql > qrs[i].l) extend(num[--ql], 1);
        while(ql < qrs[i].l) extend(num[ql++], -1);
        while(qr > qrs[i].r) extend(num[qr--], -1);
        while(qr < qrs[i].r) extend(num[++qr], 1);
        while(qt + 1 < msz && ms[qt + 1].id < qrs[i].id) change(ms[++qt], 1);
        while(qt >= 0 && ms[qt].id > qrs[i].id) change(ms[qt--], -1);

        res[qrs[i].id] = get_mex();
    }
    for(int i = 0; i < m; i++) if(res[i] != -1) cout << res[i] << "\n";


}