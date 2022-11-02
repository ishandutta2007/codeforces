#include <stdio.h>
#include <string.h>

#define N 1100

char s[N];
int vis[N], A[N], B[N];

int main() {
    //freopen("1.in", "r", stdin);
    scanf("%s",s);
    int len = strlen(s);
    for(int i = 2; i <= 1000; i ++)if(!vis[i]) {
        for(int j = 2; j * i  <= 1000; j ++) vis[i * j] = 1;
    }
    int cnt = 0;
    for(int i = 2; i <= 1000; i ++) if(!vis[i]){
        if(i * 2 > len) break;
        A[cnt ++] = i;
    }
    for(int i = 1; i <= len; i ++) vis[i] = 0;
    for(int j = 0; j < cnt; j ++) {
        int k = A[j];
        for(int i = 1; i * k <= len; i ++) vis[i * k] = 1;
    }
    int num = 0;
    for(int i = 1; i <= len; i ++) if(vis[i]) num ++;
    // printf("%d\n", num);
    for(int i = 0; i < 26; i ++) A[i] = 0;
    for(int i = 0; i < len; i ++) A[s[i] - 'a'] ++;
    for(int i = 0; i < 26; i ++) if(A[i] >= num) {
        puts("YES");
        for(int j = 1; j <= len; j ++) if(vis[j]) B[j] = i + 1;
        A[i] -= num;
        for(int j = 0; j < 26; j ++) for(int k = 0; k < A[j]; k ++) {
            for(int ii = 1; ii <= len; ii ++) if(!B[ii]) {
                B[ii] = j + 1;
                break;
            }
        }
        for(int j = 1; j <= len; j ++) printf("%c", B[j] - 1 + 'a');
        return 0;
    }
    puts("NO");
    return 0;
}