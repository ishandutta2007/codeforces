#include <stdio.h>
#include <string.h>

char a[150], b[150];

int main(){
    gets(a), gets(b);
    int lena = strlen(a), lenb = strlen(b);
    if(lena != lenb)    {printf("NO\n");    return 0;}
    int flag = 0;
    for(int i = 0; i < lena; i ++){
        if(a[i] != b[lena - i - 1]) {flag = 1; break;}
    }
    if(flag == 1)   printf("NO\n");
    else printf("YES\n");
}