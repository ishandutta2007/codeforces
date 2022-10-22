#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
char str[N];
int n , m , g;
int match[N];
int pre[N] , nxt[N];
char que[N];
int main() {
    scanf("%d%d%d" , &n , &m , &g);
    scanf("%s%s" , str + 1 , que);

    stack<int> S;
    for (int i = 1 ; i <= n ; ++ i) {
        if (str[i] == '(') {
            S.push(i);
        } else {
            int x = S.top();
            S.pop();
            match[x] = i;
            match[i] = x;
        }
    }
    nxt[0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    pre[n + 1] = n;
    int cur = g;
    for (int i = 0 ; i < m ; ++ i) {
        if (que[i] == 'L') {
            cur = pre[cur];
        } else if (que[i] == 'R') {
            cur = nxt[cur];
        } else {
            if (str[cur] == '(') {
                nxt[pre[cur]] = nxt[match[cur]];
                pre[nxt[match[cur]]] = pre[cur];
                cur = nxt[match[cur]];
            } else {
                pre[nxt[cur]] = pre[match[cur]];
                nxt[pre[match[cur]]] = nxt[cur];
                cur = nxt[cur];
            }
            while (cur > n) {
                cur = pre[cur];
            }
        }
    }
    for (int i = nxt[0] ; i <= n ; i = nxt[i]) {
        putchar(str[i]);
    }
    puts("");
}