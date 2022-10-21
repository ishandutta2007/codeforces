#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50, INF = (int)1e9;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

void copy(vector<vi> &to, vector<vi> &from) {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void init(vector<vi> &res) {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            res[i][j] = INF;
        }
    }
}

void merge(vector<vi> &res, vector<vi> &L, vector<vi> &R) {
    init(res);
    for(int i = 0; i < 5; i++) {
        for(int j = i; j < 5; j++) {
            for(int mid = i; mid <= j && mid < 5; mid++) {
                res[i][j] = min(res[i][j], L[i][mid] + R[mid][j]);

            }
        }
    }
}

void newnode(vector<vi> &res, int d) {
    res[0][0] = (d == 2);
    res[1][1] = (d == 0);
    res[2][2] = (d == 1);
    res[3][3] = (d == 6 || d == 7);
    res[4][4] = (d == 6);
    if(d == 2) res[0][1] = 0;
    if(d == 0) res[1][2] = 0;
    if(d == 1) res[2][3] = 0;
    if(d == 7) res[3][4] = 0;
}

int n, m;
string str;


struct Tree {
    vector<vi> dat[N * 4], qr[N * 4];

    void init_dat(int x, int l, int r){
        dat[x] = qr[x] = vector<vi>(5, vi(5, INF));
        if(l == r){
            init(dat[x]);
            newnode(dat[x], (int)(str[l] - '0'));
            return ;
        }
        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        merge(dat[x], dat[lson(x)], dat[rson(x)]);
    }

    vector<vi> & query(int a, int b, int x, int l, int r){
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        if(a > mid) {
            copy(qr[x], query(a, b, rson(x), mid+1, r));
            return qr[x];
        }
        if(b < mid + 1) {
            copy(qr[x], query(a, b, lson(x), l, mid));
            return qr[x];
        }
        merge(qr[x], query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
        return qr[x];
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> str;
    tree.init_dat(0, 0, n - 1);
    rep(i, 0, m) {
        int l, r; cin >> l >> r; l--, r--;
        int res = (tree.query(l, r, 0, 0, n - 1))[0][4];
        if(res == INF) res = -1;
        cout << res << '\n';
    }


}