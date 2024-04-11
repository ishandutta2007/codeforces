#include<string.h>
#include<stdio.h>
#include<math.h>

char w[1005],ob[1005][30];


bubble(char a[], int l)
{
    int i,j,k;
    char temp;
    for(j=1;j<l;j++) {
        for(i=0;i<l-j;i++) {
            if(a[i]>a[i+1]) {
                temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
            }
        }
    }
}

main()
{
    int i,j,k,t,n,l,ans;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        memset(w, 0, 1005);
        scanf("%s", w);
        l=strlen(w);
        t=0;
        for(j=0;j<l;j++) {
            if(w[j]!='1') {
                for(k=j+1;k<l;k++) {
                    if(w[k]==w[j]) w[k]='1';
                }
                ob[i][t]=w[j];
                t++;
            }
        }
        l=strlen(ob[i]);
        bubble(ob[i], l);
    }
    ans=0;
    for(i=0;i<n;i++) {
        for(j=0;j<i;j++) {
            if(strcmp(ob[i],ob[j])==0) break;
        }
        if(j==i) ans++;
    }
    printf("%d\n", ans);

}