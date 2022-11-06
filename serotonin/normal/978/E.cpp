#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int n,w,i,x,c=0,l=0,h=0;
    scanf("%I64d %I64d", &n, &w);
    for(i=0;i<n;i++) {
        scanf("%I64d", &x);
        c+=x;
        if(c<l) l=c;
        if(c>h) h=c;
    }
    if(h>w) goto end;
    if(l*(-1)>w) goto end;
    h=w-h;
    if(h+l+1<0) goto end;
    printf("%I64d\n", h+l+1);

    goto skip;
    end: printf("0\n");
    skip: ;
}