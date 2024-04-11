#include <stdio.h>
#include <string.h>

#define N 222

char s[N];
int len;
int main(){

    scanf("%s",s);
    len=strlen(s);
    for(int i=0; i<len; i++){
        int val=0;
        if(s[i]=='-'){
            if(s[i+1]=='.')val=1;
            else val=2;
            i++;
        }
        printf("%d",val);
    }
    ///return 7;
}