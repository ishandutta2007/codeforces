#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

main()
{
    int n,i,x,j,a,f=0;
    char s[105];
    scanf("%s", s);
    a=strlen(s);
    for(i=0;i<a;i++) {
        if(s[i]=='n' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') continue;
        else {
            if(i==a-1) f=1;
            else if(s[i+1]!='a' && s[i+1]!='e' && s[i+1]!='i' && s[i+1]!='o' && s[i+1]!='u') f=1;
        }
    }
    if(f==0) printf("YES\n");
    else printf("NO\n");
}