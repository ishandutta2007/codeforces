#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)1e6 + 500;

int n,m;
int a[N];
int len = 0;
int num[N];
bool good = false;


struct Tree {
    int  dat[N * 4];

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }



    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        int  LHS = query(a, b, lson(x), l, mid);
        int  RHS = query(a, b, rson(x), mid+1, r);

        return LHS + RHS;
    }

    void del(int s, int x, int l, int r) {
        if(l == r) {
            dat[x] = 0;
            return ;
        }
        int mid = (l + r) / 2;
        if(dat[lson(x)] >= s) del(s, lson(x), l, mid);
        else del(s - dat[lson(x)], rson(x), mid + 1, r);
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    int del(int s) {
        if(dat[0] < s) return -1;
        del(s, 0, 0, N - 1);
        return 1;
    }

    void print(int x, int l, int r) {
        if(l == r) {
            if(dat[x]) {
                cout << num[l];
                good = true;
            }
            return ;
        }
        int mid = (l + r) / 2;
        print(lson(x), l, mid);
        print(rson(x), mid + 1, r);
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == -1) {
            for(int j = 0; j < m; j++) if(tree.del(a[j] - j) == -1) break;
        }
        else {
            tree.update(len, 0, 0, N - 1, 1);
            num[len++] = x;
        }
    }
    tree.print(0, 0, N - 1);
    if(!good) cout << "Poor stack!";



}