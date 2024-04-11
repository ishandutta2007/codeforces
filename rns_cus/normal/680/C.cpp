#include<bits/stdc++.h>
using namespace std;

int a[30];

void prepare(){
    memset(a, 0, sizeof a);
    int i, j,  pos = 0;
    for(i = 2; i <= 100; i ++){
        for(j = 2; j < i; j ++)
            if(i % j == 0) break;
        if(j == i) a[pos ++] = i;
    }
}

int main(){
    int i, n = 0;
    char s[100];
    prepare();
    a[15] = 4; a[16] = 9; a[17] = 25; a[18] = 49;
    for(i = 0; i < 19; i ++) {
        printf("%d\n", a[i]); fflush(stdout);
        gets(s);
        if(strcmp(s, "yes") == 0) {
            if(i < 15) n ++;
            else n += 2;
        }
    }
    if(n > 1) puts("composite");
    else puts("prime");
    fflush(stdout);
    return 0;
}