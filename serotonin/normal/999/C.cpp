#include<stdio.h>
#include<math.h>
char s[500000];

main()
{
    long int n,i,j,k,x,c=0;
    scanf("%ld %ld %s", &n, &k, s);

    x='a';
    while(c<k) {
        for(i=0;i<n;i++) {
            if(s[i]==x) {
                s[i]='0';
                c++;
            }
            if(c==k) break;
        }
        x++;
    }

    for(i=0;i<n;i++) {
        if(s[i]!='0') printf("%c", s[i]);
    }
    printf("\n");
}