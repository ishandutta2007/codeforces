#include <stdio.h>

int main(){
    int w;
    scanf("%d", &w);
    if(w & 1) puts("NO");
    else if(w == 2) puts("NO");
    else puts("YES");
    return 0;
}