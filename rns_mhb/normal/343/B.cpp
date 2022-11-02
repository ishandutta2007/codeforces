#include <stdio.h>
#define N 1000001
char c,s[N];
int n;
int main() {
    //freopen("1.in","r",stdin);
    n=0;
    while(scanf("%c",&c)>0 && c!='\n') {
        if (!n) s[n++]=c;
        else {
            if (s[n-1]==c) n--;
            else s[n++]=c;
        }
    }
    puts(n?"No":"Yes");
}