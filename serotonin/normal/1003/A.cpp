#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int times[105];
    int n,i,x;
    scanf("%d", &n);
    for(i=0;i<105;i++) times[i]=0;
    for(i=0;i<n;i++) {
        scanf("%d", &x);
        times[x]++;
    }
    x=0;
    for(i=0;i<105;i++) {
        if(times[i]>x) x=times[i];
    }
    printf("%d\n", x);
}