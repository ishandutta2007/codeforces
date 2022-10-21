#include<bits/stdc++.h>
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

using namespace std;

typedef long long ll;
const int N = 200500;
ll INF = (ll)1e18 + 50;

int n,q;
int num[N];

struct Tree {
    ll add[4*N], mn[4*N];

    void push_down(int x, int l, int r) {
        if(add[x] != 0) {
            if(l < r) {
                int mid = (l + r) / 2;
                mn[ls(x)] += add[x];
                add[ls(x)] += add[x];
                mn[rs(x)] += add[x];
                add[rs(x)] += add[x];
            }
            add[x] = 0;
        }
    }

    void init(int x = 0, int l = 0, int r = n-1) {
        if(l == r) {mn[x] = num[l]; add[x] = 0; return ;}
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        add[x] = 0; mn[x] = min(mn[ls(x)], mn[rs(x)]);
    }

    ll query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return INF;

        push_down(x, l, r);

        if(l >= a && r <= b) return mn[x];

        ll LHS = query(a, b, ls(x), l, mid);
        ll RHS = query(a, b, rs(x), mid+1, r);
        return min(LHS, RHS);
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        if(l < r) push_down(x, l, r);

        if(l >= a && r <= b) {
            mn[x] += delta;
            add[x] += delta;
            return ;
        }

        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        mn[x] = min(mn[ls(x)], mn[rs(x)]);
    }

    void update(int a, int b, int delta) {
        update(a, b, 0, 0, n-1, delta);
    }

} tree;

int in[3];
int b = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    tree.init();
    cin >> q;
    string s;
    getline(cin, s);
    while(q--) {
        getline(cin, s);
        stringstream ss(s);
        b = 0;
        while(ss >> in[b]) b++;
        int l = in[0], r = in[1];
        if(b == 2) {
            if(l <= r) cout << tree.query(l, r) << "\n";

            else cout << min(tree.query(0, r), tree.query(l, n-1)) << "\n";
        }
        else {
            int val = in[2];
            if(l <= r) tree.update(l, r, val);
            else {
                tree.update(0, r, val);
                tree.update(l, n-1, val);
            }
        }
    }
}