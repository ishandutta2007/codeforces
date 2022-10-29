#include<stdio.h>

int main(){
    int x;
    char of[5],s[8];
    scanf("%d %s %s",&x,of,s);
    if(s[0]=='w'){
        if(x==5 ||x==6)printf("53\n");
        else printf("52\n");
    }else{
        if(x<=29)printf("12");
        else if(x==30)printf("11");
        else printf("7");
    }
    
    return 0;
    
}