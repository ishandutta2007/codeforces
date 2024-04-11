#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct node {
    ll sum;
    int add;

    void add_val(int x, int l, int r) {
        sum += 1LL * (r - l + 1) * x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        sum = ls.sum + rs.sum;
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                int mid = (l + r) / 2;
                dat[ls(x)].add_val(dat[x].add, l, mid);
                dat[rs(x)].add_val(dat[x].add, mid + 1, r);
            }
            dat[x].add = 0;
        }
    }

    void init() {
        fill(dat, dat + 4 * N, node{0, 0});
    }

//    int find_first(int x, int l, int r) {
//        if(l == r) return l;
//        push_down(x, l, r);
//        int mid = (l + r) / 2;
//        if(dat[ls(x)].mx > 0) return find_first(ls(x), l, mid);
//        else return find_first(rs(x), mid + 1, r);
//    }

    int query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].sum;
        return query(a, b, ls(x), l, mid) + query(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(delta, l, r);
            return ;
        }

        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree;

int n, k;
int a[N];

bool check(int len) {
    tree.init();
    tree.update(0, 0, 0, 0, len, 1);
    int ca = 0;
    ll sumb = 1;
    for(int i = 0; i <= len - 2; i++) {
        int rem = tree.query(i, i, 0, 0, len);
//        cout << rem << endl;
        while(rem-- && ca < n) {
            int ax = min(a[ca], 2 * (len - i) - 1);
            int ed = i + (ax + 2) / 2;
            tree.update(i + 2, ed, 0, 0, len, 2);
            if(ax % 2 == 0) tree.update(ed, ed, 0, 0, len, -1);
            sumb += ax  - 2;
//            cout << "adding " << a[ca] << " at " << i << endl;
            ca++;
        }
    }
    return sumb >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n, greater<>());
//    cout << check(4) << endl;
//    int x;
//    while(cin >> x) {
//        cout << check(x) << endl;
//    }

    int l = -1, r = N, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(r == N) r = -1;
    cout << r << '\n';


}