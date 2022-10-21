#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)5e5 + 500, INF = (int)1e9;
struct query {
    int r, id;
};

int n,m;
int nxt[N];
int occur[N];
int num[N];
int res[N];
vector<int> as;
vector<query> qry[N];

struct Tree {
    int dat[N * 4];

    void init() {
        fill(dat, dat + N * 4, INF);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = min(dat[lson(x)], dat[rson(x)]);
    }

    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return INF;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        int LHS = query(a, b, lson(x), l, mid);
        int RHS = query(a, b, rson(x), mid+1, r);

        return min(LHS, RHS);
    }

} tree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(occur, occur + N, -1);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        as.push_back(num[i]);
    }
    sort(as.begin(), as.end());
    as.resize(unique(as.begin(), as.end()) - as.begin());

    tree.init();
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qry[l].push_back({r, i});
    }

    for(int i = n - 1; i >= 0; i--) {
        num[i] = lower_bound(as.begin(), as.end(), num[i]) - as.begin();
        nxt[i] = occur[num[i]];
        occur[num[i]] = i;
        if(nxt[i] != -1) tree.update(nxt[i], 0, 0, n-1, nxt[i] - i);
        for(auto q : qry[i]) {
            res[q.id] = tree.query(0, q.r, 0, 0, n-1);
        }
    }
    for(int i = 0; i < m; i++) {
        cout << (res[i] == INF ? -1 : res[i]) << "\n";
    }
}