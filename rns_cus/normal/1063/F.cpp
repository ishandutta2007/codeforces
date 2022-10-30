#include <bits/stdc++.h>
using namespace std;

#define N 500500
#define K 30

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define M 27

struct node {

    node *par, *suffixlink, *chd[M];
    int l, r, pardp, children, id, st, ed, fa[K];

    node(int x) {
        par = suffixlink = NULL;
        for (int i = 0; i < M; i ++) chd[i] = NULL;
        l = r = pardp = children = 0; id = x;
    }

    inline int len() {return r - l;}
    inline int depth() {return pardp + len();}
    inline bool inedge(int pos) {return pardp <= pos && pos < depth();}

    void setedge(node *child, int l, int r, char *s) {
        chd[s[l]] = child;
        children ++;
        child -> par = this;
        child -> pardp = depth();
        child -> l = l, child -> r = r;
    }
};

int ord[N], id[N];

struct Suffix_Tree {
    char *s;
    int length, size;
    bool needwalk;
    node *root, *cur, *needsuffixlink;
    vector <node> v;
    node *newnode() {
        v[size] = node(size);
        return &v[size++];
    }
    void assign(char *str, int len) {
        s = str;
        length = len;
        size = 0;
        v.clear();
        v.reserve(length * 2 + 7);
        root = newnode();
        cur = newnode();
        root -> setedge(cur, 0, length, s);
        needsuffixlink = NULL;
        needwalk = 1;
    }

    void walkdown(int i, int j) {
        if (i > j) return;
        for (int k = i + cur -> depth(); !cur -> inedge(j - i); k += cur -> len()) cur = cur -> chd[s[k]];
    }

    void addsuffixlink() {
        if (needsuffixlink) needsuffixlink -> suffixlink = cur;
        needsuffixlink = NULL;
    }
    void build(char *str, int len) {
        assign(str, len);
        for (int i = 0, j = 1; i < len; i ++) {
            char c = s[i + 1];
            node *leaf, *split;
            for (; j <= i + 1; j ++) {
                if (needwalk) {
                    if (!cur -> suffixlink && cur -> par) cur = cur -> par;
                    cur = cur -> suffixlink ? cur -> suffixlink : root;
                    walkdown(j, i);
                }
                needwalk = 1;
                int k = i - j + 1;
                if (k == cur -> depth()) {
                    addsuffixlink();
                    if (cur -> chd[c]) {
                        cur = cur -> chd[c], needwalk = 0; break;
                    }
                    else {
                        leaf = newnode();
                        cur -> setedge(leaf, i + 1, length, s);
                    }
                }
                else {
                    int pos = cur -> l + k - cur -> pardp;
                    if (s[pos] == c) {
                        addsuffixlink();
                        if (pos != i + 1) {
                            needwalk = 0; break;
                        }
                    }
                    else {
                        split = newnode(), leaf = newnode();
                        cur -> par -> setedge(split, cur -> l, pos, s);
                        cur -> par -> children --;
                        split -> setedge(cur, pos, cur -> r, s);
                        split -> setedge(leaf, i + 1, length, s);
                        cur = split;
                        addsuffixlink();
                        if (cur -> depth() == 1) cur -> suffixlink = root;
                        else needsuffixlink = cur;
                    }
                }
            }
        }
    }
    int tot;
    void dfs(int u) {
        v[u].st = tot;
        if (!v[u].children) {
            int x = v[u].depth();
            ord[tot] = u, id[x] = tot ++;
        }
        for (int i = 0; i < M; i ++) {
            if (v[u].chd[i]) dfs(v[u].chd[i] -> id);
        }
        v[u].ed = tot - 1;
    }
    void prepare() {
        tot = 0, dfs(0);
        for (int i = 0; i < size; i ++) {
            if (v[i].par) v[i].fa[0] = v[i].par -> id;
            else v[i].fa[0] = -1;
        }
        for (int k = 1; k < K; k ++) {
            for (int i = 0; i < size; i ++) {
                if (v[i].fa[k-1] != -1) v[i].fa[k] = v[v[i].fa[k-1]].fa[k-1];
                else v[i].fa[k] = -1;
            }
        }
    }
    int snode(int l, int r) {
        int u = ord[id[length-l+1]];
        for (int k = K - 1; k >= 0; k --) {
            if (v[u].fa[k] == -1) continue;
            if (v[v[u].fa[k]].depth() >= r - l + 1) u = v[u].fa[k];
        }
        return u;
    }
} ST;

int n, dp[N], mx[N << 2];
char s[N];

#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)

int query(int v, int vl, int vr, int l, int r) {
    if (l > vr || vl > r) return 0;
    if (l <= vl && vr <= r) return mx[v];
    return max(query(le, vl, mi, l, r), query(ri, mi + 1, vr, l, r));
}

void update(int v, int vl, int vr, int p, int x) {
    if (vl == vr) mx[v] = max(mx[v], x);
    else {
        if (p > mi) update(ri, mi + 1, vr, p, x);
        else update(le, vl, mi, p, x);
        mx[v] = max(mx[le], mx[ri]);
    }
}

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i ++) s[i] -= 'a'; s[n+1] = 26;
    ST.build(s + 1, n);
    ST.prepare();
    int ans = 0;
    for (int i = n, j = n + 1, k; i; i --) {
        for (k = dp[i+1] + 1; k >= 2; k --) {
            while (j > i + k) {
                j --;
                update(1, 1, n, id[n+1-j], dp[j]);
            }
            int x = ST.snode(i, i + k - 2);
            if (query(1, 1, n, ST.v[x].st, ST.v[x].ed) >= k - 1) break;
            x = ST.snode(i + 1, i + k - 1);
            if (query(1, 1, n, ST.v[x].st, ST.v[x].ed) >= k - 1) break;
        }
        dp[i] = k; ans = max(ans, k);
    }
    printf("%d\n", ans);

    return 0;
}