#include<bits/stdc++.h>
using namespace std;

#define N 310

int t, n, cnt[5], v[N];
char s[N][N];

int main() {
    v['X'] = 0, v['O'] = 1;
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%s", &s[i]);
        for(int i = 0; i < 3; i ++) cnt[i] = 0;
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) if(s[i][j] != '.') cnt[(i + j + v[s[i][j]]) % 3] ++;
        int k = min_element(cnt, cnt + 3) - cnt;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(s[i][j] != '.' && (i + j + v[s[i][j]]) % 3 == k) putchar('X' + 'O' - s[i][j]);
                else putchar(s[i][j]);
            }
            puts("");
        }
    }
}