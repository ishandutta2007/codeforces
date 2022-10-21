#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50, K = 5, INF = (int)1e9 + 50;
typedef pair<int, int> P;

struct qry {
    int l, r, k, id;
};

struct node {
    P p[5];
    node() {
        fill(p, p + 5, P{-1, -1});
    }

    void update(int cnt, int x) {
        for(int i = 0; i < 5; i++) {
            if(p[i].first == -1) {
                p[i] = {cnt, x};
                return;
            }
            if(p[i].second == x) {
                p[i].first++;
                for(int j = i; j >= 1; j--) {
                    if(p[j-1].first < p[j].first) swap(p[j-1], p[j]);
                    else break;
                }
                return ;
            }
        }
        if(p[4].first >= cnt) return ;
        p[4] = {cnt, x};
        for(int j = 4; j >= 1; j--) {
            if(p[j-1].first < p[j].first) swap(p[j-1], p[j]);
        }
    }
};

int n, q;
int a[N];
int res[N];
int cnt[N];
vector<int> ocu[N];
vector<qry> Ql[N], Qr[N];

int count(int l, int r, int x) {
    return lower_bound(ocu[x].begin(), ocu[x].end(), r + 1)
            - lower_bound(ocu[x].begin(), ocu[x].end(), l);
}

void check_queries(vector<qry> &Q, node &nd) {
    for(const auto &qr : Q) {
        for(int idx = 0; idx < 5; idx++) {
            int x = nd.p[idx].second;
            if(x == -1) break;
            if(count(qr.l, qr.r, x) > (qr.r - qr.l + 1) / qr.k)
                res[qr.id] = min(res[qr.id], x);
        }
    }
}
void solve(int L, int R, vector<qry> qrs) {
    if(L == R) {
        for(auto qr : qrs) res[qr.id] = min(res[qr.id], a[L]);
        return ;
    }
    int mid = (L + R) / 2;
    vector<qry> LQ, RQ;
    for(const auto &qr : qrs) {
        if(qr.r <= mid) LQ.push_back(qr);
        else if(qr.l >= mid + 1) RQ.push_back(qr);

        if(qr.l <= mid && qr.r >= mid) Ql[qr.l].push_back(qr);
        if(qr.r >= mid + 1 && qr.l <= mid + 1) Qr[qr.r].push_back(qr);
    }
    node nd;
    for(int i = mid; i >= L; i--) {
        cnt[a[i]]++;
        nd.update(cnt[a[i]], a[i]);
        check_queries(Ql[i], nd);
    }
    for(int i = mid; i >= L; i--) cnt[a[i]] = 0;
    node nd2;
    for(int i = mid + 1; i <= R; i++) {
        cnt[a[i]]++;
        nd2.update(cnt[a[i]], a[i]);
        check_queries(Qr[i], nd2);
    }
    for(int i = mid + 1; i <= R; i++) cnt[a[i]] = 0;


    for(int i = L; i <= R; i++) Ql[i].clear(), Qr[i].clear();
    solve(L, mid, LQ);
    solve(mid + 1, R, RQ);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ocu[a[i]].push_back(i);
    }
    fill(res, res + q, INF);
    vector<qry> qrs;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k; l--, r--;
        qrs.push_back({l, r, k, i});
    }
    solve(0, n - 1, qrs);
    for(int i = 0; i < q; i++) {
        cout << (res[i] == INF ? -1 : res[i]) << "\n";
    }

}