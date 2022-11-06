#include<bits/stdc++.h>
using namespace std;

main() {
    int a[105],n,m,i,j,k,x,ans,e,mx;
    for(i=0;i<105;i++) a[i]=0;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        scanf("%d", &x);
        a[x]++;
    }

    sort(a,a+105);

    int flag=0;
    for(i=100;i>0;i--) {
        k=0;
        for(j=104;j>0;j--) {
            if(a[j]==0) break;
            k+=a[j]/i;
        }
        if(k>=n) break;
    }

    printf("%d\n", i);
}