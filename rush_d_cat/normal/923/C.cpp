#include <iostream>
using namespace std;
const int N = 9000000;
int ch[N][2], sz[N], tot = 1;
int a[N], n;
void add(int x) {
    int now = 1; ++ sz[1];
    for (int i = 30; i >= 0; i --) {
        int f = (x>>i)&1;
        if (!ch[now][f]) 
            ch[now][f] = ++ tot;
        now = ch[now][f], ++ sz[now]; 
    }
} 
int query(int x) {
    int now = 1; int ret = 0;
    for (int i = 30; i >= 0; i --) {
        int f = (x>>i)&1;
        if (ch[now][f] && sz[ch[now][f]]) now = ch[now][f], -- sz[now];
        else ret |= 1<<i, now = ch[now][f^1], -- sz[now];
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        add(x);
    }
    for (int i = 1; i <= n; i ++) {
        printf("%d\n", query(a[i]));
    }
}