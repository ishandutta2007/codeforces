#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[101];
    scanf("%s", s);
    int i,x,p=0,l=0;
    x=strlen(s);
    for(i=0;i<x;i++) {
        if(s[i]=='-') l++;
        if(s[i]=='o') p++;
    }
    if(p==0) printf("YES\n");
    else if(l%p==0) printf("YES\n");
    else printf("NO\n");
}