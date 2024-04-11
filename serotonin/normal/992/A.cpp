#include<stdio.h>
#include<math.h>

int a[200005];
const long int q=100001;

main()
{
    long int n,i,x,c=0;
    scanf("%ld", &n);
    for(i=0;i<n;i++) {
        scanf("%ld", &x);
        if(a[x+q]!=1 && x!=0) c++;
        a[x+q]=1;
    }
    printf("%ld\n", c);
}