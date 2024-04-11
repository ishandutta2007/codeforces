#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
    scanf("%s", s);
    int len = strlen(s), i, x = 0, y = 0;
    if(len & 1) {puts("-1"); return 0;}
    for(i = 0; i < len; i ++) {
        if(s[i] == 'L') x --;
        if(s[i] == 'R') x ++;
        if(s[i] == 'D') y --;
        if(s[i] == 'U') y ++;
    }
    printf("%d", abs(x) + abs(y) >> 1);
}