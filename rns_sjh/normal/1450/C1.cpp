#include<bits/stdc++.h>
using namespace std;

#define N 310

int t, n, cnt[5];
char s[N][N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%s", &s[i]);
        for(int i = 0; i < 3; i ++) cnt[i] = 0;
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) if(s[i][j] == 'X') cnt[(i + j) % 3] ++;
        int k = min_element(cnt, cnt + 3) - cnt;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(s[i][j] == 'X' && (i + j) % 3 == k) putchar('O');
                else putchar(s[i][j]);
            }
            puts("");
        }
    }
}