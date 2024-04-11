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
const int N = (int)1e5 + 50, INF = (int)1e9;

#define lson(x) 2*x+1
#define rson(x) 2*x+2


struct node {
    int mat[3][3];

    void set(int x) {
        memset(mat, 0, sizeof(mat));
        mat[x][x] = 1;
    }

    void merge(node &LHS, node &RHS) {
        rep(i, 0, 3) {
            rep(j, i, 3) {
                mat[i][j] = INF;
                rep(k, i, j + 1) {
                    mat[i][j] = min(mat[i][j], LHS.mat[i][k] + RHS.mat[k][j]);
//                    cout << mat[i][j] << endl;
                }
            }
        }
    }
};

string str;

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r) {
            dat[x].set(str[l] - 'a');
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
            dat[x].set(val);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cin >> str;
    tree.init_dat(0, 0, n - 1);
    while(q--) {
        int i; char c;
        cin >> i >> c; i--;
        tree.update(i, 0, 0, n - 1, c - 'a');
        node &qr = tree.dat[0];
        int mn = INF;
        rep(j, 0, 3) mn = min(mn, qr.mat[0][j]);
        cout << mn << '\n';
    }
}