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
    ll add[4*N], mx[4*N];

    void push_down(int x, int l, int r) {
        if(add[x] != 0) {
            if(l < r) {
                int mid = (l + r) / 2;
                mx[ls(x)] += add[x];
                add[ls(x)] += add[x];
                mx[rs(x)] += add[x];
                add[rs(x)] += add[x];
            }
            add[x] = 0;
        }
    }

    void init(int x = 0, int l = 0, int r = n-1) {
        if(l == r) {mx[x] = num[l]; add[x] = 0; return ;}
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        add[x] = 0; mx[x] = max(mx[ls(x)], mx[rs(x)]);
    }

    ll query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return INF;

        push_down(x, l, r);

        if(l >= a && r <= b) return mx[x];

        ll LHS = query(a, b, ls(x), l, mid);
        ll RHS = query(a, b, rs(x), mid+1, r);
        return max(LHS, RHS);
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        if(l < r) push_down(x, l, r);

        if(l >= a && r <= b) {
            mx[x] += delta;
            add[x] += delta;
            return ;
        }

        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        mx[x] = max(mx[ls(x)], mx[rs(x)]);
    }

    void update(int a, int b, int delta) {
        update(a, b, 0, 0, n-1, delta);
    }

    int find(int x, int l, int r) {
        if(l == r) return l;
        push_down(x, l, r);
        int mid = (l + r) / 2;
        if(mx[rs(x)] > 0) return find(rs(x), mid + 1, r);
        else return find(ls(x), l, mid);
    }


} tree;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int loc, tp;
        cin >> loc >> tp; loc--;
        if(tp == 0) tree.update(0, loc, -1);
        else {
            cin >> num[loc];
            tree.update(0, loc, 1);
        }
        if(tree.query(0, n - 1) <= 0) cout << -1 << "\n";
        else {
            cout << num[tree.find(0, 0, n - 1)] << "\n";
        }
    }
}