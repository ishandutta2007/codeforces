#include <bits/stdc++.h>
using namespace std;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2e5 + 50, INF = (int)1e9;

struct node {
    int mx, add;

    void add_val(int x) {
        mx += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mx = max(ls.mx, rs.mx);
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
    }

    int qmax(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].mx;

        return max(qmax(a, b, ls(x), l, mid), qmax(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);
        if(l >= a && r <= b) {
            dat[x].add_val(delta);
            return ;
        }
        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree[2];

struct seg {
    int l, r, c;
    void read() {
        cin >> l >> r >> c; c--;
    }
};

int n;
seg p[N];
vi xs;
int len;

int lower(int val) {
    return (int)(lower_bound(all(xs), val) - xs.begin());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    xs.push_back(0);
    rep(i, 0, n) p[i].read(), xs.push_back(p[i].r);
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    sort(p, p + n, [](const seg &s1, const seg &s2) {
        return s1.r < s2.r;
    });
    len = sz(xs);
    int curmax = 0;
    int r = 0;
    for(int i = 0; i < n; i = r) {
        while(r < n && p[i].r == p[r].r) r++;
        for(int j = i; j < r; j++) {
            int cl = lower(p[j].l);
//            cout << j << " " << cl << endl;
            tree[p[j].c].update(0, cl - 1, 0, 0, len - 1, 1);
        }

        int cr = lower(p[i].r);
        int maxdp = max(tree[0].qmax(0, cr, 0, 0, len - 1), tree[1].qmax(0, cr, 0, 0, len - 1));
        curmax = max(curmax, maxdp);
//        cout << i << ": " << maxdp << endl;
        rep(c, 0, 2) tree[c].update(cr, cr, 0, 0, len - 1, maxdp);
    }
    cout << curmax << '\n';
}