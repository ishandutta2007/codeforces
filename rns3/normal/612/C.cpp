#include <cstdio>
#include <cstring>

#define N 1001000

char s[N], f[300], a[N], g[300];
int n, ans;

int run() {
    int k = 0;
    for(int i = 0; i < n; i ++) {
        if(f[s[i]]) a[k ++] = s[i];
        else {
            if(k < 1) return -1;
            if(g[s[i]] != a[k-1]) ans ++;
            k --;
        }
    }
    if(k) return -1;
    return ans;
}

void init() {
    f['<'] = f['('] = f['{'] = f['['] = 1;
    g['<'] = '>'; g['('] = ')'; g['{'] = '}'; g['['] = ']';
    g['>'] = '<'; g[')'] = '('; g['}'] = '{'; g[']'] = '[';
}

int main() {
    init();
    gets(s);
    n = strlen(s);
    int rt = run();
    if(rt < 0) puts("Impossible");
    else printf("%d\n", rt);
    return 0;
}