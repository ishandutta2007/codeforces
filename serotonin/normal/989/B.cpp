#include<stdio.h>
#include<math.h>
#include<string.h>

main()
{
    char s[2005];
    int i,j,n,p,f=0;
    scanf("%d %d", &n, &p);
    scanf("%s", s);
    for(i=0;i<n-p;i++) {
        if(s[i]=='.') {
            if(s[i+p]=='.') {
                s[i]='1';
                s[i+p]='0';
                f++;
            }
            else {
                if(s[i+p]=='1') s[i]='0';
                if(s[i+p]=='0') s[i]='1';
                f++;
            }
        }
        else {
            if(s[i+p]=='.') {
                if(s[i]=='1') s[i+p]='0';
                if(s[i]=='0') s[i+p]='1';
                f++;
            }
            else {
                if(s[i]!=s[i+p]) f++;
            }
        }
    }
    if(f>0) {
        for(i=0;i<n;i++) {
            if(s[i]=='.') printf("0");
            else printf("%c", s[i]);
        }
        printf("\n");
    }
    else printf("No\n");
}