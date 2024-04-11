#include<stdio.h>
#include<math.h>
int nums[100005],a[100005],done[100005];

main()
{
    long long int n,m,x,y,i,d=0,ans=0;
    for(i=0;i<100005;i++) nums[i]=0;
    scanf("%I64d", &n);
    for(i=0;i<n;i++) {
        scanf("%I64d", &x);
        a[i]=x;
        done[x]=1;
        nums[x]++;
        if(nums[x]==1) d++;
    }

    for(i=0;i<n;i++) {
        x=a[i];
        nums[x]--;
        if(nums[x]==0) d--;
        if(done[x]==1) ans+=d;
        done[x]=0;
    }
    printf("%I64d\n", ans);
}