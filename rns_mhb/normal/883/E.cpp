#include <bits/stdc++.h>
using namespace std;

#define N 55
char s[N], t[N];
bool vis[300];
int a[N], as, m;
bitset <300> bst, now;

int n;

int main() {
    scanf("%d", &n);
    scanf("%s", t);
    for (int i = 0; i < n; i ++) {
        if (t[i] == '*') a[as ++] = i;
        else vis[t[i]] = 1;
    }
    a[as] = -1;
    bst.set();
    for (scanf("%d", &m); m --; ) {
        scanf("%s", s);
        now.reset();
        bool flag = 0;
        for (int i = 0; i < as && !flag; i ++) if (vis[s[a[i]]]) flag = 1;
        for (int i = 0, j = 0; i < n && !flag; i ++) {
            if (i == a[j]) {
                now[s[i]] = 1;
                j ++;
            }
            else if (s[i] != t[i]) flag = 1;
        }
        if (flag) continue;
        bst &= now;
    }
    printf("%d\n", bst.count());
	return 0;
}