#include<bits/stdc++.h>
using namespace std;

#define N 100010
const int mod = 1e9 + 7;

struct bus {
    int s, t;
    bool operator < (const bus &b) const {return t < b.t;}
    void in() {scanf("%d%d", &s, &t); s ++, t ++;}
} b[N];

map<int, int> tree;
int tot;

void update(int x, int y) {
    tot = (tot + y) % mod;
    for(; x < mod; x += x & -x) tree[x] = (tree[x] + y) % mod;
}

int query(int x) {
    int ret = 0;
    for(; x; x -= x & -x) ret = (ret + tree[x]) % mod;
    return ret;
}

int main() {
    int n, m, i, j, k, tmp;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i ++) b[i].in();
    sort(b + 1, b + m + 1);
    if(b[m].t != n + 1) {puts("0"); return 0;}
    update(1, 1);
    for(i = 1; i <= m; i = j) {
        j = i;
        while(b[i].t == b[j].t) j ++;
        for(k = i, tmp = 0; k < j; k ++) tmp = (tmp + (tot - query(b[k].s - 1) + mod) % mod) % mod;
        update(b[i].t, tmp);
    }
    cout << (tot - query(n) + mod) % mod << endl;
}