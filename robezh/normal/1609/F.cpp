#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<int, int> P;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)1e6 + 2;
const ll INF = (ll)1e18 + 50;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

ll readInt () {
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

struct node {
    int pmax, sum, cnt;

    void merge(node &LHS, node &RHS) {
        pmax = max(LHS.pmax, RHS.pmax + LHS.sum);
        sum = LHS.sum + RHS.sum;
        cnt = (LHS.pmax == pmax ? LHS.cnt : 0) + (RHS.pmax + LHS.sum == pmax ? RHS.cnt : 0);
    }
};

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r) {
            dat[x] = {0, 0, 1};
            return;
        }

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].sum += val;
            dat[x].pmax = dat[x].sum;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }
} tree;

int n;
ll a[N];
struct Qr {
    int x, l, r;
    bool add;
};

int mnl[N], mxl[N];
int bt[N];
//vector<Qr> qrs[60];
Qr qrs[N * 4];
int idx[N * 4];
int off[60], cnt[60];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

//    cout << sizeof(tree) << endl;
    cin >> n;
//    scanf("%d", &n);
//    n = readInt();
//    n = (int)1e6;
    rep(i, 0, n) {
        cin >> a[i];
        rep(b, 0, 60) bt[i] += (a[i] >> b & 1);
        cnt[bt[i]] += 4;
    }
    rep(i, 1, 60) off[i] = off[i - 1] + cnt[i - 1];
    vector<pll> Smn = {{-INF, -1}}, Smx = {{INF, -1}};
    rep(i, 0, n) {
        while(Smn.back().first > a[i]) Smn.pop_back();
        mnl[i] = Smn.back().second + 1;
        Smn.push_back({a[i], i});
        while(Smx.back().first < a[i]) Smx.pop_back();
        mxl[i] = Smx.back().second + 1;
        Smx.push_back({a[i], i});
    }
    Smn = {{-INF, n}}, Smx = {{INF, n}};
    for (int i = n - 1; i >= 0; i--) {
        ll cb = bt[i];
        while(Smn.back().first >= a[i]) Smn.pop_back();
        int mnr = Smn.back().second - 1;

        Smn.push_back({a[i], i});
        qrs[off[cb]++] = {mnl[i], i, mnr, true};
        qrs[off[cb]++] = {i + 1, i, mnr, false};

        while(Smx.back().first <= a[i]) Smx.pop_back();
        int mxr = Smx.back().second - 1;
        Smx.push_back({a[i], i});
        qrs[off[cb]++] = {mxl[i], i, mxr, true};
        qrs[off[cb]++] = {i + 1, i, mxr, false};

//        cout << i << ", mnl: " << mnl[i] << " mnr: " << mnr << ", mxl: " << mxl[i] << " mxr: " << mxr << endl;
    }
    tree.init_dat(0, 0, n - 1);
    ll fres = 0;
    int laoff = 0;
    iota(idx, idx + 4 * n, 0);
    int las = 0;
    rep(b, 0, 60) {
        sort(qrs + laoff, qrs + off[b], [](const Qr &q1, const Qr &q2) {
            return q1.x < q2.x;
        });
//        cout << qrs[b].capacity() << endl;
        int r = laoff;
        for(int i = laoff; i < off[b]; i = r) {
            while(r < off[b] && qrs[r].x == qrs[i].x) r++;
//            cout << qrs[i].x << " " << tree.dat[0].cnt << " " << tree.dat[0].mx << endl;
            if(tree.dat[0].pmax == 2) fres += 1LL * tree.dat[0].cnt * (qrs[i].x - las);
            las = qrs[i].x;
            rep(j, i, r) {
                auto &q = qrs[j];
                int ad = q.add ? 1 : -1;
                tree.update(q.l, 0, 0, n - 1, ad);
                if(q.r + 1 < n) tree.update(q.r + 1, 0, 0, n - 1, -ad);
//                cout << "adding " << q.l << " " << q.r << " " << ad << endl;
            }

        }
        laoff = off[b];

    }
    cout << fres << endl;
//    printf("%I64d", fres);

}