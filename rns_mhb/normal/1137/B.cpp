#include<bits/stdc++.h>
using namespace std;

#define N 500010

char s[N], t[N];
int nxt[N];

int main() {
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    nxt[m-1] = m;
    for(int i = m - 2; i >= 0; i --) {
        int k = nxt[i+1];
        while(k < m && t[k-1] != t[i]) k = nxt[k];
        if(t[k-1] == t[i]) k --;
        nxt[i] = k;
    }
    int cnt[2] = {};
    for(int i = 0; i < n; i ++) if(s[i] == '0') cnt[0] ++;
    cnt[1] = n - cnt[0];
    for(int i = 0; i < n; i ++) {
        char ch = t[i%nxt[0]];
        int c = ch - '0';
        if(cnt[c] == 0) {
            for(int j = i; j < n; j ++) putchar('0' + 1 - c);
            break;
        }
        cnt[c] --;
        putchar(ch);
    }
}