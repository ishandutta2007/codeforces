#include <stdio.h>
#define N 60001
int n,a[N];
int ans=0;
int main() {
    //freopen("B.in","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",a+i);
        for (int j=0;j<i;j++) if (a[i]<a[j]) ans+=1;
    }
    printf("%lf\n",double(ans)*2-((ans&1)?1:0));
}