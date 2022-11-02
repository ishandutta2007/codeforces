#include<bits/stdc++.h>
using namespace std;

#define N 55

char s[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i]+1);
    for(int i = 1; i <= n; i ++) for(int j = i+1; j <= n; j ++) for(int k = 1; k <= m; k ++) for(int h = k+1; h <= m; h ++) {
        int cnt = 0;
        if(s[i][k] == '#') cnt ++;
        if(s[i][h] == '#') cnt ++;
        if(s[j][k] == '#') cnt ++;
        if(s[j][h] == '#') cnt ++;
        if(cnt == 3) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}