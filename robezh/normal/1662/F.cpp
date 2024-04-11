#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

#define lson(x) 2 * x + 1
#define rson(x) 2 * x + 2
const int N = (int)2e5 + 50;
const int INF = (int)1e9 + 50;

struct Tree {
    int dat[4 * N];
    void init(int x, int l, int r, vi &a) {
        if(l == r) {
            dat[x] = a[l];
            return ;
        }
        int mid = (l + r) / 2;
        init(lson(x), l, mid, a);
        init(rson(x), mid + 1, r, a);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r) {
        if(l == r) {
            dat[x] = -INF;
            return ;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid + 1, r);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    vi fs;

    void find_above(int x, int l, int r, int val) {
        if(l == r) {
//            cout << "val: " << dat[x] << endl;
            fs.push_back(l);
            return ;
        }
        int mid = (l + r) / 2;
        if(dat[lson(x)] >= val) find_above(lson(x), l, mid, val);
        if(dat[rson(x)] >= val) find_above(rson(x), mid + 1, r, val);
    }

    void solve(int a, int b, int x, int l, int r, int val) {
        if(r < a || b < l) return ;
        int mid = (l + r) / 2;
        if(a <= l && r <= b) {
            if(dat[x] >= val) find_above(x, l, r, val);
            return ;
        }
        solve(a, b, lson(x), l, mid, val);
        solve(a, b, rson(x), mid + 1, r, val);
    }
} tree[2];


int n, a, b;
int p[N];
int dis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> a >> b; a--, b--;
        rep(i, 0, n) cin >> p[i];
        vi xs(n, 0);
        rep(i, 0, n) xs[i] = p[i] + i;
        tree[0].init(0, 0, n - 1, xs);
        rep(i, 0, n) xs[i] = p[i] - i;
        tree[1].init(0, 0, n - 1, xs);


        fill(dis, dis + n, INF);

        queue<int> que;
        auto visit = [&](const int i, int d) {
            dis[i] = d;
            rep(b, 0, 2) tree[b].update(i, 0, 0, n - 1);
            que.push(i);
        };
        visit(a, 0);
        while(!que.empty()) {
            int i = que.front(); que.pop();
//            cout << "in " << i << endl;
            tree[0].fs.clear();
            tree[0].solve(max(0, i - p[i]), i - 1, 0, 0, n - 1, i);
            for (int x : tree[0].fs) {
//                cout << "lfet visiting " << x << endl;
                visit(x, dis[i] + 1);
            }
            tree[1].fs.clear();
            tree[1].solve(i + 1,  min(n - 1, i + p[i]), 0, 0, n - 1, -i);
            for (int x : tree[1].fs) {

//                cout << "right  visiting " << x << endl;
                visit(x, dis[i] + 1);
            }
        }
        cout << dis[b] << '\n';
    }

}