#include <bits/stdc++.h>
using namespace std;

const int SZ1 = 2000, SZ2 = 50, MAXN = 1e5 + 10;
int a[MAXN], oa[MAXN], cnt[2*MAXN], cntcnt[MAXN], ans[MAXN], n, q;
int Q, L, R;
vector<array<int, 3>> qs, cqs;

struct qry {
    int idx, prv, l, r;
    bool operator<(const qry &o) const {
        return make_tuple(prv / SZ1, l / SZ1, r) < make_tuple(o.prv / SZ1, o.l / SZ1, o.r);
    }
};
vector<qry> queries;

void aL() {
    cntcnt[cnt[oa[L]]]--;
    cnt[oa[L]]--;
    cntcnt[cnt[oa[L]]]++;
    L++;
}

void sL() {
    L--;
    cntcnt[cnt[oa[L]]]--;
    cnt[oa[L]]++;
    cntcnt[cnt[oa[L]]]++;
}

void aR() {
    R++;
    cntcnt[cnt[oa[R]]]--;
    cnt[oa[R]]++;
    cntcnt[cnt[oa[R]]]++;
}

void sR() {
    cntcnt[cnt[oa[R]]]--;
    cnt[oa[R]]--;
    cntcnt[cnt[oa[R]]]++;
    R--;
}

void aQ() {
    oa[cqs[Q][0]] = cqs[Q][2];
    if(L <= cqs[Q][0] && cqs[Q][0] <= R) {
        cntcnt[cnt[cqs[Q][1]]]--;
        cnt[cqs[Q][1]]--;
        cntcnt[cnt[cqs[Q][1]]]++;
        cntcnt[cnt[cqs[Q][2]]]--;
        cnt[cqs[Q][2]]++;
        cntcnt[cnt[cqs[Q][2]]]++;
    }
    Q++;
}

void sQ() {
    Q--;
    oa[cqs[Q][0]] = cqs[Q][1];
    if(L <= cqs[Q][0] && cqs[Q][0] <= R) {
        cntcnt[cnt[cqs[Q][2]]]--;
        cnt[cqs[Q][2]]--;
        cntcnt[cnt[cqs[Q][2]]]++;
        cntcnt[cnt[cqs[Q][1]]]--;
        cnt[cqs[Q][1]]++;
        cntcnt[cnt[cqs[Q][1]]]++;
    }
}

void solve() {
    sort(queries.begin(), queries.end());
    for(auto q : queries) {
        while(L < q.l)
            aL();
        while(L > q.l)
            sL();
        while(R < q.r)
            aR();
        while(R > q.r)
            sR();
        while(Q < q.prv)
            aQ();
        while(Q > q.prv)
            sQ();
        for(int i = 1;;i++) {
            if(cntcnt[i] == 0) {
                ans[q.idx] = i;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    vector<int> all;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    for(int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        qs.push_back({t, x, y});
        if(t == 2)
            all.push_back(y);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    map<int, int> to;
    for(int i = 0; i < all.size(); i++)
        to[all[i]] = i + 1;
    for(int i = 1; i <= n; i++) {
        a[i] = to[a[i]];
        oa[i] = a[i];
        cnt[a[i]]++;
    }
    int curcq = 0, curaq = 0;
    for(int i = 0; i < q; i++) {
        if(qs[i][0] == 2) {
            qs[i][2] = to[qs[i][2]];
            cqs.push_back({qs[i][1], a[qs[i][1]], qs[i][2]});
            a[qs[i][1]] = qs[i][2];
            curcq++;
        }
        else
            queries.push_back({curaq++, curcq, qs[i][1], qs[i][2]});
    }
    for(int i = 1; i < 2*MAXN; i++)
        cntcnt[cnt[i]]++;

    // Preprocessing done hopefully

    Q = 0;
    L = 1;
    R = n;
    solve();

    for(int i = 0; i < queries.size(); i++)
        cout << ans[i] << '\n';
}