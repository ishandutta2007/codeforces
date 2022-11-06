#include<stdio.h>
#include<math.h>
char a[100][2];
main()
{
    int n,c,i,j,k=0,ans[100],max=0,x;
    char s[105];
    for(i=0;i<100;i++) ans[i]=1;

    scanf("%d %s", &n, s);
    for(i=1;i<n;i++) {
        for(j=1;j<=k;j++) {
            if(a[j][0]==s[i-1] && a[j][1]==s[i]) {
                ans[j]++;
                break;
            }
        }
        if(j<=k) continue;

        k++;
        a[k][0]=s[i-1];
        a[k][1]=s[i];
    }

    for(i=1;i<=k;i++) {
        if(ans[i]>max) {
            max=ans[i];
            x=i;
        }
    }

    printf("%c%c\n", a[x][0], a[x][1]);
}