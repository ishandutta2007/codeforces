#include<bits/stdc++.h>
using namespace std;

#define N 1010

struct word{
    int len;
    bool b[N];
    bool nxt() {
        int i;
        for(i = len; i; i --) if(!b[i]) break;
        if(!i) return 0;
        b[i ++] = 1;
        for(; i <= len; i ++) b[i] = 0;
        return 1;
    }
    void init(int l) {
        memset(b, 0, sizeof b);
        len = l;
    }
    void print() {
        for(int i = 1; i <= len; i ++) {
            if(b[i]) putchar('1');
            else putchar('0');
        }
        puts("");
    }
} w[N];

int a[N], c[N];

bool cmp(int i, int j) {return a[i] < a[j];}

int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) scanf("%d", a + i), c[i] = i;
    sort(c + 1, c + n + 1, cmp);
    w[c[1]].init(a[c[1]]);
    for(i = 2; i <= n; i ++) {
        w[c[i]] = w[c[i - 1]];
        if(!w[c[i]].nxt()) {
            puts("NO");
            return 0;
        }
        w[c[i]].len = a[c[i]];
    }
    puts("YES");
    for(i = 1; i <= n; i ++) w[i].print();
}