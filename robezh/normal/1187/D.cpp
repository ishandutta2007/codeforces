#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef pair<int, int> P;
typedef long long ll;
const int N = (int)3e5 + 50, INF = (int)1e9;

int n;
int a[N], b[N];
queue<int> ocu[N];

struct Tree {
    int dat[N * 4];


    void init_dat(int l, int r, int x){
        if(l == r){dat[x] = a[l]; return ;}

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x] = min(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = INF;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid+1, r);
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


bool solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) while(!ocu[i].empty()) ocu[i].pop();
    for(int i = 0; i < n; i++) cin >> a[i], ocu[a[i]].push(i);
    tree.init_dat(0, n - 1, 0);
    for(int i = 0; i < n; i++) cin >> b[i];
    int r = 0;
    for(int i = 0; i < n; i = r) {
        r = i + 1;
        multiset<int> S;
        S.insert(b[i]);
        while(r < n && b[r] >= b[r-1]) r++;

        vector<P> qrys;
        for(int j = i; j < r; j++) {
            if(ocu[b[j]].empty()) return false;
            int id = ocu[b[j]].front(); ocu[b[j]].pop();
            tree.update(id, 0, 0, n - 1);
            qrys.push_back({id, b[j]});
        }
        for(auto p : qrys) {
            if(tree.query(0, p.first - 1, 0, 0, n - 1) <= p.second) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}