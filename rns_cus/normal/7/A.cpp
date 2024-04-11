#include<stdio.h>
#include<memory.h>
#define N 20
char s[N][N];
int main(){
    while(scanf("%s", s[0]) > 0){
        int k = 0, i;
        for(i = 0; i < 7; i ++)scanf("%s", s[i+1]);
        int ans = 0;
        for(int i = 0; i < 8; i ++)if(strcmp(s[i], "BBBBBBBB") == 0) {
            for(int j = 0; j < 8; j ++)s[i][j] = 'W';
            ans ++;
        }
        for(int i = 0; i < 8; i ++){
            int ok = 0;
            for(int j = 0; j < 8; j ++)if(s[j][i] == 'B')ok = 1;
            ans += ok;
        }
        printf("%d\n", ans);
    }
    return 0;
}