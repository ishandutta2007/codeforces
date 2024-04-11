#include <bits/stdc++.h>

using namespace std;

#define N 111

int n;
char s[N][N], T[N], tp[N], TT[N];
int flag[N];
int g[N];

int main()  {
    scanf("%d", &n);
    for(int i = 0; i < n ;i ++) {
        scanf("%s", s[i]);
        strlwr(s[i]);
        g[i] = strlen(s[i]);
    }
    scanf("%s", T); strcpy(TT, T); strlwr(T);
    scanf("%s", tp); strlwr(tp);
    int len = strlen(T);
    for(int i = 0; i < len; i ++) {
        for(int j = 0; j < n; j ++) {
            int k;
            for(k = 0; k < g[j]; k ++) {
                if(T[i + k] != s[j][k]) break;
            }
            if(k == g[j]){
                for(k = 0; k < g[j]; k ++) flag[i + k] = 1;
            }
        }
    }
    for(int i = 0; i < len; i ++) if(flag[i]) {
        if(T[i] != tp[0]) {
            if('a' <= TT[i] && TT[i] <= 'z') TT[i] = tp[0];
            else TT[i] = tp[0] - 'a' + 'A';
        } else {
            if(tp[0] == 'a') {
                if('a' <= TT[i] && TT[i] <= 'z') {
                    TT[i] = 'b';
                } else TT[i] = 'B';
            } else {
                if('a' <= TT[i] && TT[i] <= 'z') {
                    TT[i] = 'a';
                } else TT[i] = 'A';
            }
        }
    }
    puts(TT);
    return 0;
}