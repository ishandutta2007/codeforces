#include<bits/stdc++.h>
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

int n,q;
string str;
int num[N];

struct node {
    int c00, c01, c10, c11;
    bool flip;

    void flip_node() {
        swap(c00, c11);
        swap(c01, c10);
        flip ^= 1;
    }

    void merge(node &ls, node &rs) {
        c00 = ls.c00 + rs.c00;
        c11 = ls.c11 + rs.c11;
        c01 = max(ls.c01 + rs.c11, ls.c00 + rs.c01);
        c10 = max(ls.c10 + rs.c00, ls.c11 + rs.c10);
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].flip) {
            if(l < r) {
                dat[ls(x)].flip_node();
                dat[rs(x)].flip_node();
            }
            dat[x].flip = false;
        }
    }

    void init(int x = 0, int l = 0, int r = n-1) {
        if(l == r) {
            dat[x].flip = false;
            dat[x].c00 = (num[l] == 0);
            dat[x].c11 = (num[l] == 1);
            dat[x].c01 = dat[x].c10 = 1;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].flip = false;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    node query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {0, 0, 0, 0, false};

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x];

        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid+1, r);
        node res;
        res.merge(LHS, RHS);
        return res;
    }

    void update(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].flip_node();
            return ;
        }

        update(a, b, ls(x), l, mid);
        update(a, b, rs(x), mid+1, r);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void update(int a, int b) {
        update(a, b, 0, 0, n-1);
    }

} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    cin >> str;
    for(int i = 0; i < n; i++) num[i] = (str[i] == '7');
    tree.init(0, 0, n - 1);
    while(q--) {
        string str;
        cin >> str;
        if(str[0] == 'c') {
            node res = tree.query(0, n - 1);
            cout << tree.query(0, n - 1).c01 << "\n";
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            tree.update(l, r);
        }
    }
}