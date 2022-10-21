#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 500, mod = (int)1e9 + 7;

int n;
P p[N];
int rs[N];

struct node {
    int mn;
    int cnt;

    void merge(node &LHS, node &RHS) {
        mn = min(LHS.mn, RHS.mn);
        cnt = (LHS.mn == mn ? LHS.cnt : 0) + (RHS.mn == mn ? RHS.cnt : 0);
        cnt %= mod;
    }
};

struct Tree {
    node dat[N * 4];


    void init_dat(int l, int r, int x){
        if(l == r){dat[x].mn = p[l].first; dat[x].cnt = 1;return ;}

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int val, int cnt){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].mn = val;
            dat[x].cnt = cnt;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val, cnt);
        else update(pos, rson(x), mid+1, r, val, cnt);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {mod + 5, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid+1, r);
        res.merge(LHS, RHS);
        return res;
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].second >> p[i].first;
    sort(p, p + n);
    for(int i = n - 1; i >= 0; i--) {
        int l = (int)(lower_bound(p, p + n, make_pair(p[i].second, -1)) - p);
        node q;
        if(l < n) {
            q = tree.query(l, n - 1, 0, 0, n - 1);
            q.mn -= p[i].second - p[i].first;
        }
        else q = {p[i].first, 1};
        tree.update(i, 0, 0, n - 1, q.mn, q.cnt);
    }
    cout << tree.query(0, n - 1, 0, 0, n - 1).cnt << endl;



}