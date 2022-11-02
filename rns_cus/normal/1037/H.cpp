#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIGMA 256
#define N 200020
char S[N];
struct node {
    node *par, *suffixlink, *chd[SIGMA];
    int l, r, pardp, children, st, ed;
    node() {
        par = suffixlink = NULL;
        for (int i = 0; i < SIGMA; i ++) chd[i] = NULL;
        l = r = pardp = children = 0;
    }
    inline int len() {
        return r - l;
    }
    inline int depth() {
        return pardp + len();
    }
    inline bool inedge(int pos) {
        return pardp <= pos && pos < depth();
    }
    void setedge(node *child, int l, int r, char *s) {
        chd[s[l]] = child;
        children ++;
        child -> par = this;
        child -> pardp = depth();
        child -> l = l, child -> r = r;
    }
    void print() {
        if (this == NULL) return;
        for (int i = l - pardp; i < r; i ++) putchar(S[i]);
    }
};
struct Suffix_Tree {
    char *s;
    int length, size, cnt, rk[N];
    bool needwalk;
    node *root, *cur, *needsuffixlink;
    vector <node> v;
    node *newnode() {
        v[size] = node();
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
        for (int k = i + cur -> depth(); !cur -> inedge(j - i); k += cur ->
                len()) cur = cur -> chd[s[k]];
    }
    void addsuffixlink() {
        if (needsuffixlink) needsuffixlink -> suffixlink = cur;
        needsuffixlink = NULL;
    }
    void build(char *str, int len) {
        assign(str, len); cnt = 0;
        for (int i = 0, j = 1; i < len; i ++) {
            char c = s[i + 1];
            node *leaf, *split;
            for (; j <= i + 1; j ++) {
                if (needwalk) {
                    if (!cur -> suffixlink && cur -> par) cur = cur ->
                                par;
                    cur = cur -> suffixlink ? cur -> suffixlink : root;
                    walkdown(j, i);
                }
                needwalk = 1;
                int k = i - j + 1;
                if (k == cur -> depth()) {

                    addsuffixlink();
                    if (cur -> chd[c]) {


                        cur = cur -> chd[c], needwalk = 0;
                        break;
                    } else {
                        leaf = newnode();
                        cur -> setedge(leaf, i + 1, length, s);
                    }
                } else {

                    int pos = cur -> l + k - cur -> pardp;
                    if (s[pos] == c) {

                        addsuffixlink();
                        if (pos != i + 1) {

                            needwalk = 0;
                            break;
                        }
                    } else {

                        split = newnode(), leaf = newnode();
                        cur -> par -> setedge(split, cur -> l, pos,
                                              s);
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
    void dfs(node *x) {
        x -> st = cnt + 1;
        if (!x -> children) rk[++cnt] = x -> depth();
        for (int i = 0; i < SIGMA; i ++) if (x -> chd[i]) dfs(x -> chd[i]);
        x -> ed = cnt;
    }
} ST;
int q;
char s[N];
stack <node*> sta;
vector <int> vec[N<<2];

#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)
#define all(v) vec[v].begin(), vec[v].end()

void build(int v, int vl, int vr, int *a) {
    if (vl == vr) {
        vec[v].assign(1, a[vl]);
        return;
    }
    build(le, vl, mi, a), build(ri, mi + 1, vr, a);
    vec[v].resize(vr - vl + 1);
    merge(all(le), all(ri), vec[v].begin());
}

int query(int v, int vl, int vr, int l, int r, int dn, int up) {
    if (up < dn) return 0;
    if (l <= vl && vr <= r) return lower_bound(all(v), up + 1) - lower_bound(all(v), dn);
    if (l > vr || vl > r) return 0;
    return query(le, vl, mi, l, r, dn, up) + query(ri, mi + 1, vr, l, r, dn, up);
}

int main() {
    scanf("%s", S);
    int n = strlen(S);
    ST.build(S, n);
    ST.dfs(ST.root);
    scanf("%d", &q);
    build(1, 1, n + 1, ST.rk);
    while (q --) {
        int l, r;
        scanf("%d %d %s", &l, &r, s);
        int len = strlen(s);
        while (!sta.empty()) sta.pop();
        node *nd = ST.root;
        sta.push(nd);
        int fg = 0;
        for (int i = 0; i <= len;) {
            if (nd -> chd[s[i]]) {
                nd = nd -> chd[s[i]];
                int j;
                for (j = 0; j < nd -> len(); j ++) {
                    if (s[i+j] != S[nd->l+j]) break;
                }
                if (j < nd -> len()) {
                    if (s[i+j] < S[nd->l+j]) fg = j + 1, sta.push(nd);
                    break;
                }
                i += nd -> len();
                sta.push(nd);
            }
            else break;
        }
        int id = -1;
        while (!sta.empty()) {
            nd = sta.top(); sta.pop();
//            cout << fg << ' ' <<  nd -> pardp << ' ' << nd -> l << ' ' << nd -> r << endl;
            int L = fg ? nd -> pardp + fg : nd -> depth() + 1;
            int i;
            for (i = s[L-1] + 1; i < SIGMA; i ++)
                if (nd -> chd[i]) break;
            if (!fg && i == SIGMA) continue;
//            cout << (fg ? nd : nd -> chd[i]) -> st << ' ' <<  nd -> ed << ' ' << n + L - r << ' ' << n - l + 1 << endl;
            if (query(1, 1, n + 1, (fg ? nd : nd -> chd[i]) -> st, nd -> ed, n + L - r, n - l + 1)) {
                id = i;
                if (fg) id = SIGMA + 1;
                else {
                    for (i = s[L-1] + 1; i < SIGMA; i ++) {
                        if (nd -> chd[i] && query(1, 1, n + 1, nd -> chd[i] -> st, nd -> chd[i] -> ed, n + L - r, n - l + 1)) break;
                    }
                    if (i == SIGMA) while (1); id = i;
                }
                break;
            }
            fg = 0;
        }
        if (id < 0) puts("-1");
        else {
            if (id < SIGMA) nd -> print(), putchar(id);
            else {
                nd -> par -> print();
                for (int j = 0; j < fg; j ++) putchar(S[nd->l+j]);
            }
            puts("");
        }
    }
//    }
    return 0;
}