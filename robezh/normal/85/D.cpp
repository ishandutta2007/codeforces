#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)2e5 + 500;

int n,m;
vector<int> a;
string str[N];
int qnum[N];
int in[N];

struct node {
    ll val[5];
    int cnt;
    node() {
        fill(val, val + 5, 0);
        cnt = 0;
    }
    void merge(node &ls, node &rs) {
        cnt = ls.cnt + rs.cnt;
        for(int i = 0; i < 5; i++) val[i] = ls.val[i] + rs.val[((i-ls.cnt)%5 + 5) % 5];
    }
};

struct Tree {
    node dat[N * 4];

    void update(int pos, int x, int l, int r, int val, bool add){
        int mid = (l + r) / 2;
        if(l == r) {
            if(add) {
                dat[x].val[0] = val;
                dat[x].cnt = 1;
            }
            else {
                dat[x].val[0] = 0;
                dat[x].cnt = 0;
            }
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val, add);
        else update(pos, rson(x), mid+1, r, val, add);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int val, bool add) {
        update(pos, 0, 0, n-1, val, add);
    }

    ll query() {
        return dat[0].val[2];
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> str[i];
        if(str[i][0] != 's') cin >> qnum[i], a.push_back(qnum[i]);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    for(int i = 0; i < m; i++) {
        if(str[i][0] != 's') {
            int cur = lower_bound(a.begin(), a.end(), qnum[i]) - a.begin();
            if(str[i][0] == 'd') tree.update(cur, -1, false);
            else tree.update(cur, qnum[i], true);
        }
        else {
            cout << tree.query() << "\n";
        }
    }
}