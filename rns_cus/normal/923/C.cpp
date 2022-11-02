#include <bits/stdc++.h>
using namespace std;

#define N 300300
#define K 30

int n, a[N], p[N];

struct Node{
    int cnt, nxt[2];
    void init() {
        cnt = 0;
        memset(nxt, 0, sizeof nxt);
    }
};

struct Trie{
    Node node[N<<4];
    int tot;
    int init() {
        tot = 0;
        node[0].init();
    }
    int newnode() {
        node[++tot].init();
        return tot;
    }
    void insert(int x) {
        int nd = 0;
        for (int i = 0; i < K; i ++) {
            int c = x >> K - i - 1 & 1;
            int &k = node[nd].nxt[c];
            if (!k) k = newnode();
            node[nd=k].cnt ++;
        }
    }
    int search(int x) {
        int nd = 0, rlt = 0;
        for (int i = 0; i < K; i ++) {
            int c = x >> K - i - 1 & 1;
            if (!node[nd].nxt[c]) c ^= 1;
            rlt = rlt << 1 | c;
            int &k = node[nd].nxt[c];
            node[nd=k].cnt --;
            if (!node[k].cnt) k = 0;
        }
        return rlt;
    }
} T;

int main() {
    scanf("%d", &n); T.init();
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0, x; i < n; i ++) scanf("%d", &x), T.insert(x);
    for (int i = 0; i < n; i ++) {
        int k = T.search(a[i]);
        printf("%d ", k ^ a[i]);
    }
}