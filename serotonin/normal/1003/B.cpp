#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int a,b,x,n,i,j,y;
    scanf("%d %d %d", &a, &b, &x);
    n=a+b;
    char bn[n];
    if(a<=b) {
        for(i=0;i<n;i++) bn[i]='1';

        if(x%2==0) {
            y=0;
            for(i=1;y<x;i+=2) {
                bn[i]='0';
                y+=2;
                a--;
            }
            for(j=i-1;a>0;j++) {
                bn[j]='0';
                a--;
            }
        }
        else {
            y=0;
            for(i=1;y<x-1;i+=2) {
                bn[i]='0';
                y+=2;
                a--;
            }
            for(j=n-1;a>0;j--) {
                bn[j]='0';
                a--;
            }
        }
    }

    if(a>b) {
        for(i=0;i<n;i++) bn[i]='0';

        if(x%2==0) {
            y=0;
            for(i=1;y<x;i+=2) {
                bn[i]='1';
                y+=2;
                b--;
            }
            for(j=i-1;b>0;j++) {
                bn[j]='1';
                b--;
            }
        }
        else {
            y=0;
            for(i=1;y<x-1;i+=2) {
                bn[i]='1';
                y+=2;
                b--;
            }
            for(j=n-1;b>0;j--) {
                bn[j]='1';
                b--;
            }
        }
    }

    
    for(i=0;i<n;i++) printf("%c", bn[i]);
    printf("\n");
}