#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)3e5 + 50;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct node {
    int sum, suf;

    void add(int val) {
        sum += val;
        suf = max(sum, 0);
    }
};

node merge(node L, node R) {
    return {L.sum + R.sum, max(R.sum + L.suf, R.suf)};
}

struct Tree {
    node dat[4 * N];
    void init(int n) {
        fill(dat, dat + 4 * n, node{0, 0});
    }

    void update(int pos, int x, int l, int r, int val) {
        if(l == r) {dat[x].add(val); return ;}
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid + 1, r, val);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }
} tree;

int n;
int loc[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    tree.init(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x; x--; loc[x] = i;
    }
    int cur = n - 1;
    for(int i = 0; i < n; i++) {
        while(cur >= 0 && tree.dat[0].suf == 0) {
            tree.update(loc[cur--], 0, 0, n - 1, 1);
        }
        cout << cur + 2 << " ";
        int q; cin >> q; q--;
        tree.update(q, 0, 0, n - 1, -1);
    }
}