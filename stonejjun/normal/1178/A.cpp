#include<bits/stdc++.h>
using namespace std;

int arr[1010101];
int arr2[1010101];
int dp[1010101];

int main()
{
    int i,j,k,l,m,n,cnt=0,hap=0,go=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        hap+=arr[i];
    }
    hap=(hap/2)+1;
    cnt=1;
    arr2[cnt]=1;
    go=arr[1];
    for(i=2;i<=n;i++)
    {
        if(go>=hap) break;
        if(arr[1]>=2*arr[i])
        {
            go+=arr[i];
            cnt++;
            arr2[cnt]=i;
        }
    }
    if(go>=hap)
    {
        printf("%d\n",cnt);
        for(i=1;i<=cnt;i++)
            printf("%d ",arr2[i]);
    }
    else
    {
        printf("0");
    }

}