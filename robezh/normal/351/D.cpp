#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)1e5 + 5, INF = (int)1e9;

struct node {
    int mx, sum;

    void merge(node &LHS, node &RHS) {
        sum = LHS.sum + RHS.sum;
        mx = max(LHS.mx, RHS.mx);
    }
};

struct Tree {
    node dat[N * 4];

    void update(int pos, int x, int l, int r, int jump, int s){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = {jump, s};
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, jump, s);
        else update(pos, rson(x), mid+1, r, jump, s);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid+1, r);
        res.merge(LHS, RHS);
        return res;
    }
} tree;

int n, q;
int a[N];
int nxt[N];
int la[N], jp[N];

int fres[N];
vector<pii> qrs[N];

struct seg {
    int l, r, p;
};

vector<seg> S[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    cin >> q;
    rep(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        qrs[l].push_back({r, i});
    }
//    rep(i, 0, N) S[i].push({INF, INF});
    fill(la, la + N, INF);

    for(int i = n - 1; i >= 0; i--) {
        int v = a[i];
        nxt[i] = la[v];
        if(la[v] == INF) {
            jp[i] = INF;
        } else {
            int newlen = la[v] - i;
            if(!S[v].empty() && S[v].back().p == newlen) S[v].back().l -= newlen;
            else S[v].push_back({i, la[v], newlen});
            jp[i] = nxt[S[v].back().r];
        }
//        cout << i << " " << jp[i] << endl;
        la[v] = i;
    }
    memset(la, -1, sizeof(la));
    for(int i = n - 1; i >= 0; i--) {
        int v = a[i];
        if(la[v] != -1) tree.update(la[v], 0, 0, n - 1, 0, 0);
        tree.update(i, 0, 0, n - 1, jp[i], 1);
        for(pii &p : qrs[i]) {
            auto nd = tree.query(i, p.first, 0, 0, n - 1);
//            cout << p.second << " " << nd.mx << endl;
            fres[p.second] = nd.sum + (nd.mx <= p.first);
        }
        la[v] = i;
    }
    rep(i, 0, q) cout << fres[i] << '\n';
}