#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N = 222222;
const int INF = 1111111111;

const int MAXMARK = 0;
const int MINMARK = 1;

int n, k, d;
int a[N], tail, bak[N];
vector<int> qmax, qmin;
map<int, int> last;

struct Node {
    int l, r;
    int flagMin, flagMax, ans, minV, maxV;
}tree[N * 4];

void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].flagMin = tree[root].flagMax = tree[root].ans = INF;
    tree[root].minV = INF;
    tree[root].maxV = INF;
    if (l == r)
        return ;
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
}

void update(int x) {
    tree[x].ans = min(tree[x << 1].ans, tree[x << 1 | 1].ans);
    tree[x].minV = min(tree[x << 1].minV, tree[x << 1 | 1].minV);
    tree[x].maxV = min(tree[x << 1].maxV, tree[x << 1 | 1].maxV);
}

void fresh(int x, int type, int v) {
    if (type == MAXMARK) {
        tree[x].flagMax = v;
        tree[x].maxV = v;
        tree[x].ans = min(INF, tree[x].maxV + tree[x].minV);
    } else {
        tree[x].flagMin = v;
        tree[x].minV = tree[x].l - v;
        tree[x].ans = min(INF, tree[x].maxV + tree[x].minV);
    }
}

void pushDown(int x) {
    if (tree[x].flagMin != INF) {
        fresh(x << 1, MINMARK, tree[x].flagMin);
        fresh(x << 1 | 1, MINMARK, tree[x].flagMin);
        tree[x].flagMin = INF;
    }
    if (tree[x].flagMax != INF) {
        fresh(x << 1, MAXMARK, tree[x].flagMax);
        fresh(x << 1 | 1, MAXMARK, tree[x].flagMax);
        tree[x].flagMax = INF;
    }
}

int getPos(int x, int l, int r, int limit) {
    if (l == r)
        return l;
    pushDown(x);
    int mid = (l + r) >> 1, res;
    if (tree[x << 1].ans <= limit) {
        res = getPos(x << 1, l, mid, limit);
    } else {
        res = getPos(x << 1 | 1, mid + 1, r, limit);
    }
    update(x);
    return res;
}

void modify(int x, int l, int r, int ql, int qr, int v, int type) {
    if (ql > r || qr < l)
        return;
    if (ql <= l && r <= qr) {
        fresh(x, type, v);
        return;
    }
    pushDown(x);
    int mid = (l + r) >> 1;
    modify(x << 1, l, mid, ql, qr, v, type);
    modify(x << 1 | 1, mid + 1, r, ql, qr, v, type);
    update(x);
}

int main() {
    scanf("%d %d %d", &n, &k, &d);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        bak[i] = a[i];
    }   
    
    int ansl = 1, ansr = 1;
    if (d == 0) {
        for(int i = 1, j = 1; i <= n; i = j) {
            while(j <= n && a[j] == a[i])
                j++;
            if (j - i > ansr - ansl) {
                ansl = i;
                ansr = j;
            }
        }
        printf("%d %d\n", ansl, ansr - 1);
        return 0;
    }
    build(1, 1, n);
    qmin.push_back(0);
    qmax.push_back(0);
    for(int i = 1, pre = 0; i <= n; i++) {
        a[i] /= d;
        while((int)qmax.size() > 1 && a[qmax.back()] <= a[i])
            qmax.pop_back();
        while((int)qmin.size() > 1 && a[qmin.back()] >= a[i])
            qmin.pop_back();
        modify(1, 1, n, qmax.back() + 1, i, a[i], MAXMARK);
        qmax.push_back(i);
        modify(1, 1, n, qmin.back() + 1, i, a[i], MINMARK);
        qmin.push_back(i);
        if (i > 1 && abs(bak[i] - bak[i - 1]) % d) {
            pre = i - 1;
        } else {
            pre = max(pre, last[bak[i]]);
        }
        last[bak[i]] = i;
        modify(1, 1, n, 1, pre, INF - 1, MAXMARK);
        int lp = getPos(1, 1, n, k + i);
        if (i - lp > ansr - ansl) {
            ansl = lp;
            ansr = i;
        }
        //printf("%d\n", pre);
    }
    
    printf("%d %d\n", ansl, ansr);
    return 0;
}