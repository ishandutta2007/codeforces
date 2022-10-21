#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, INF = (int)1e9;

struct Tree {
    int mn[N * 4];

    void init_dat(){
        fill(mn, mn + 4 * N, -INF);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            mn[x] = val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        mn[x] = min(mn[lson(x)], mn[rson(x)]);
    }

    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return INF;
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return mn[x];
        return min(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }
} tree;

int n, a[N];
int la[N];
int good[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(la, la + N, -1);
    tree.init_dat();
    rep(i, 0, n) {
        cin >> a[i]; a[i]--;
        if(la[a[i]] != i - 1 && tree.query(0, a[i] - 1, 0, 0, n - 1) > la[a[i]]) {
            good[a[i]] = 1;
        }
        tree.update(a[i], 0, 0, n - 1, i);
        la[a[i]] = i;
    }
    rep(v, 0, n + 1) {
        if(la[v] != n - 1 && tree.query(0, v - 1, 0, 0, n - 1) > la[v]) {
            good[v] = 1;
        }
    }
    int ans = 0;
    while(good[ans]) ans++;
    cout << ans + 1 << '\n';
}