#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define mc 26

int sz, n, k;
bool a[N], b[N];
char in[N];

struct node{
    int nxt[mc];
}P[N];

int newnode() {
    sz ++;
    for (int i = 0; i < mc; i ++) P[sz].nxt[i] = 0;
    return sz;
}

void add(char *s) {
    int len = strlen(s), v = 0;
    for (int i = 0; i < len; i ++) {
        if (P[v].nxt[s[i] - 'a'] == 0) P[v].nxt[s[i] - 'a'] = newnode();
        v = P[v].nxt[s[i] - 'a'];
    }
}

void dfs(int v = 0) {
    int bb = 0;
    a[v] = 0;
    b[v] = 0;
    for (int i = 0; i < mc; i ++) {
        int vv = P[v].nxt[i];
        if (vv == 0) continue;
        else {
            dfs(vv);
            bb = 1;
            if (!a[vv]) a[v] = 1;
            if (!b[vv]) b[v] = 1;
        }
    }
    if (!bb) {
        a[v] = 0;
        b[v] = 1;
    }
    return;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", in);
        add(in);
    }
    dfs();
    if (a[0] == 0) puts("Second");
    else {
        if (b[0] == 1) puts("First");
        else {
            if (k % 2) puts("First");
            else puts("Second");
        }
    }
}