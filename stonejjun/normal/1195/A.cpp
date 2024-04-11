#include<bits/stdc++.h>
using namespace std;

int arr[101010];
int main()
{
    int i,j,k,l,m,n,cnt=0,ans=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
    arr[j]++;
    }
    for(i=1;i<=k;i++)
    {
        if(arr[i]%2) cnt++;
    }
    ans=(n-cnt);
    printf("%d",ans+(cnt+1)/2);

}