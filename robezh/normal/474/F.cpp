#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, LOGN = 19;
const int INF = (int)1e9 + 500;
typedef pair<int, int> P;

#define ls(x) 2*x+1
#define rs(x) 2*x+2

int n, m;
int num[N];

struct node {
    int fre, mn, gcd;

    void merge(node &l, node &r) {
        mn = min(l.mn, r.mn);
        fre = (mn == l.mn ? l.fre : 0) + (mn == r.mn ? r.fre : 0);
        gcd = __gcd(l.gcd, r.gcd);
    }
};

struct Tree{
    node nd[4 * N];

    void init_dat(int x = 0, int l = 0, int r = n-1){
        if(l == r){
            nd[x].gcd = nd[x].mn = num[l];
            nd[x].fre = 1;
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(ls(x), l, mid);
        init_dat(rs(x), mid+1, r);

        nd[x].merge(nd[ls(x)], nd[rs(x)]);
    }

    node query(int a, int b, int x = 0, int l = 0, int r = n-1){
        if(r < a || b < l) return {0, INF, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return nd[x];

        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid+1, r);

        node res;
        res.merge(LHS, RHS);
        return res;
    }
} tree;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    tree.init_dat();
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--, r--;
        node res = tree.query(l, r);
        int live = res.mn == res.gcd ? res.fre : 0;
        cout << r - l + 1 - live << "\n";
    }

}