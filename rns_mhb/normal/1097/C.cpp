#include<bits/stdc++.h>
using namespace std;

#define N 500010

char s[N];
int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%s", s);
        int m = strlen(s);
        int L = 0, R = 0;
        for(int i = 0, cur = 0; i < m; i ++) {
            if(s[i] == '(') cur --;
            else cur ++;
            if(cur > L) L = cur;
        }
        for(int i = m - 1, cur = 0; i >= 0; i --) {
            if(s[i] == ')') cur --;
            else cur ++;
            if(cur > R) R = cur;
        }
        if(L && R) continue;
        if(L) a[L] ++;
        else b[R] ++;
    }
    int ans = b[0] >> 1;
    for(int i = 1; i < N; i ++) ans += min(a[i], b[i]);
    printf("%d\n", ans);
}