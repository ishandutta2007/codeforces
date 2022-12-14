#include <stdio.h>
#include <string.h>

char s[4][4];

int main(){
    //freopen("c.in", "r", stdin);

    for(int i=0; i<3; i++) scanf("%s", s[i]);
    int cntx = 0, cnt0 = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(s[i][j] == 'X') cntx ++;
            if(s[i][j] == '0') cnt0 ++;
        }
    }

    int gasx = 0, gas0 = 0;

    for(int i=0; i<3; i++){
        if(strcmp(s[i], "XXX") == 0) gasx ++;
        if(strcmp(s[i], "000") == 0) gas0 ++;
    }
    for(int j=0; j<3; j++){
        if(s[0][j] == 'X' && s[1][j] == 'X' && s[2][j] == 'X') gasx ++;
        if(s[0][j] == '0' && s[1][j] == '0' && s[2][j] == '0') gas0 ++;
    }
    if(s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X') gasx ++;
    if(s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X') gasx ++;
    if(s[0][0] == '0' && s[1][1] == '0' && s[2][2] == '0') gas0 ++;
    if(s[0][2] == '0' && s[1][1] == '0' && s[2][0] == '0') gas0 ++;

    if(cntx > cnt0 + 1 || cntx < cnt0) {puts("illegal"); return 0;}
    if(cntx == cnt0 + 1){
        if(gas0 || gasx > 2) {puts("illegal"); return 0;}
        if(gasx) {puts("the first player won"); return 0;}
        if(cntx == 5) {puts("draw"); return 0;}
        puts("second"); return 0;
    }
    if(cntx == cnt0){
        if(gasx || gas0 > 2) {puts("illegal"); return 0;}
        if(gas0) {puts("the second player won"); return 0;}
        puts("first"); return 0;
    }

    return 0;
}