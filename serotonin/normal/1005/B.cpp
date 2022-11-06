#include<stdio.h>
#include<string.h>
#include<math.h>

char s[200005],t[200005];

int main()
{
    int x,i,ans,ls,lt;
    scanf("%s %s", s, t);
    x=0;
    ls=strlen(s);
    lt=strlen(t);

    while(x<ls || x<lt) {
        if(s[ls-1-x]!=t[lt-1-x]) break;
        x++;
    }

    printf("%d\n", ls+lt-x-x);
}