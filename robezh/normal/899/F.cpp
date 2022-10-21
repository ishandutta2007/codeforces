#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)2e5 + 500;

int n,m;
string str;
set<int> S[256];

struct Tree {
    int n;
    int dat[N * 4];

    void init_dat(int l, int r, int x){
        if(l == r){dat[x] = 1; return ;}

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    void update(int pos, int x, int l, int r){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x]--;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid+1, r);
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        int LHS = query(a, b, lson(x), l, mid);
        int RHS = query(a, b, rson(x), mid+1, r);

        return LHS + RHS;
    }

    int find(int pos, int x, int l, int r) {
        if(l == r) return l;
        int mid = (l + r) / 2;
        if(dat[lson(x)] > pos) return find(pos, lson(x), l, mid);
        else return find(pos - dat[lson(x)], rson(x), mid + 1, r);
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> str;
    for(int i = 0; i < n; i++) {
        S[str[i]].insert(i);
    }
    tree.init_dat(0, n - 1, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--, b--;
        int l = tree.find(a, 0, 0, n - 1), r = tree.find(b, 0, 0, n-1);
        auto it = S[c].lower_bound(l);
        while(it != S[c].end() && *it <= r) {
            tree.update(*it, 0, 0, n-1);
            it = S[c].erase(it);
        }
    }
    for(int i = 0; i < n; i++) if(tree.query(i, i, 0, 0, n-1)) cout << str[i];
    cout << endl;

}