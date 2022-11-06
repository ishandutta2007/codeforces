#include<stdio.h>
#include<math.h>
#include<string.h>

main()
{
    char s[111];
    int i,j,x,l;
    scanf("%s", s);
    l=strlen(s);
    for(i=0;i<l-2;i++) {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') break;
        if(s[i]=='A' && s[i+1]=='C' && s[i+2]=='B') break;
        if(s[i]=='C' && s[i+1]=='A' && s[i+2]=='B') break;
        if(s[i]=='B' && s[i+1]=='A' && s[i+2]=='C') break;
        if(s[i]=='C' && s[i+1]=='B' && s[i+2]=='A') break;
        if(s[i]=='B' && s[i+1]=='C' && s[i+2]=='A') break;
    }
    if(i==l-2 || l<3) printf("No\n");
    else printf("Yes\n");
}