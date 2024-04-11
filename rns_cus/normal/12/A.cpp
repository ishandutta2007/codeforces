///a
#include<stdio.h>

char m[4][4];

int main()
{
    int fg=0;

    for(int i=0;i<3;i++){
        scanf("%s",m[i]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(m[i][j]!=m[2-i][2-j])fg=1;
        }
    }
    if(fg)puts("NO");
    else puts("YES");
    return 0;
}