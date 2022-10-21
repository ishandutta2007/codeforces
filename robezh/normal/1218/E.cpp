#include <bits/stdc++.h>
using namespace std;

// p           | k  | g
// 469762049     26   3
// 998244353     23   3
// 1004535809    21   3
// 2281701377    27   3

typedef long long ll;
typedef pair<int, int> P;
#define lson(x) 2*x+1
#define rson(x) 2*x+2
const int N = (1 << 16) + 50, mod = 998244353, g = 3;

int rev[N], w[2][N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
}

int pow(int x, int k){
    int c = 1;
    for(; k; k >>= 1, x = int(x * 1LL * x % mod)) if(k & 1) c = int(c * 1LL * x % mod);
    return c;
}

void init(int len){
    for(int i = 0; i < len; i++){
        int y = 0, x = i;
        for(int k = 1; k < len; k *= 2, x >>= 1) (y <<= 1) |= (x & 1);
        rev[i] = y;
    }
    w[0][0] = w[1][0] = 1;
    int mp = pow(g, (mod-1)/len), ni = pow(mp, mod - 2);
    for(int i = 1; i < len; i++){
        w[0][i] = int(w[0][i-1] * 1LL * mp % mod);
        w[1][i] = int(w[1][i-1] * 1LL * ni % mod);
    }
}

void NTT(vector<int> &y, int on, int len){
    y.resize(len, 0);
    for(int i = 0; i < len; i++) if(i > rev[i]){int tmp = y[i]; y[i] = y[rev[i]], y[rev[i]] = tmp;}
    for(int h = 2; h <= len; h <<= 1) {
        int wi = len / h;
        for (int j = 0; j < len; j += h) {
            int l = 0;
            for (int k = j; k < j + h / 2; k++) {
                int u = y[k];
                int t = int(1LL * w[on==-1][l] * y[k + h / 2] % mod);
                y[k] = (u + t) % mod;
                y[k + h / 2] = ((u - t) % mod + mod) % mod;
                l += wi;
            }
        }
    }

    if(on == -1){
        int ni = pow(len, mod-2);
        for(int i = 0; i < len; i++) y[i] = int(1LL * y[i] * ni % mod);
    }
}

int n, k;
int a[N];

vector<int> mult_poly(vector<int> a, vector<int> b) {
    int len = 1;
    while(len < a.size() + b.size() + 1) len *= 2;
    init(len);
    NTT(a, 1, len);
    NTT(b, 1, len);
    for(int i = 0; i < len; i++) a[i] = (int)(1LL * a[i] * b[i] % mod);
    NTT(a, -1, len);
    while(!a.empty() && a.back() == 0) a.pop_back();
    return a;
}

struct node {
    vector<int> sum;

    void merge(node &LHS, node &RHS) {
        sum = mult_poly(LHS.sum, RHS.sum);
    }
};

struct Tree {
    node dat[N * 4];

    void init_dat(int l, int r, int x){
        if(l == r){dat[x].sum = {1, (-a[l] % mod + mod) % mod};return ;}

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    vector<vector<int> > nds;
    void query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return ;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) {
            nds.push_back(dat[x].sum);
            return ;
        }

        query(a, b, lson(x), l, mid);
        query(a, b, rson(x), mid+1, r);
    }

    vector<int> get_freq(int a, int b) {
        if(a > b) return {1};
        nds.clear();
        query(a, b, 0, 0, n - 1);
        priority_queue<P, vector<P>, greater<> > pque;
        for(int i = 0; i < nds.size(); i++) pque.push({nds[i].size(), i});
        while(pque.size() > 1) {
            int x = pque.top().second; pque.pop();
            int y = pque.top().second; pque.pop();
            nds[y] = mult_poly(nds[y], nds[x]);
            nds[x].clear();
            pque.push({nds[y].size(), y});
        }
        return nds[pque.top().second];
    }
} tree;

vector<int> get_increased(vector<int> t, int d, int len) {
    t.resize(len + 1, 0);
    vector<int> p(len + 1, 0);
    for(int i = 0; i <= len; i++) {
        t[i] = (int)((1LL * t[i] * fac[len - i]) % mod);
    }
    p[0] = 1;
    for(int i = 1; i <= len; i++) {
        p[i] = (int)(1LL * p[i-1] * d % mod * inv[i] % mod);
    }
    t = mult_poly(t, p);
    t.resize(len + 1, 0);
    for(int i = 0; i <= len; i++) t[i] = (int)(1LL * t[i] * facinv[len - i] % mod);
    return t;

}

int query(int a, int b, int q, int d) {
    auto L = tree.get_freq(0, a - 1), R = tree.get_freq(b + 1, n - 1), M = tree.get_freq(a, b);
    L = mult_poly(L, R);
    L = get_increased(L, q % mod, n - (b - a + 1));
    M = get_increased(M, (q - d) % mod, b - a + 1);
    auto res = mult_poly(L, M);
    return k >= res.size() ? 0 : (res[k] % mod + mod) % mod;
}

int main(){
    init_fac();
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    tree.init_dat(0, n - 1, 0);

    int q;
    cin >> q;
    while(q--) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int off, i, d;
            cin >> off >> i >> d; i--;
            cout << query(i, i, off, d - a[i]) << "\n";
        }
        else {
            int off, l, r, d;
            cin >> off >> l >> r >> d; l--, r--;
            cout << query(l, r, off, d) << "\n";
        }
    }
}