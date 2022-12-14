#include <stdio.h>
#include <string.h>

char s[101];

int main(){
    //freopen("a.in", "r", stdin);
    int cnt = 0, ans = 0;
    while(gets(s) > 0){
        if(s[0] == '+') cnt ++;
        else if(s[0] == '-') cnt --;
        else {
            ans += strlen(strchr(s, ':') + 1) * cnt;
        }
    }
    printf("%d\n", ans);
}