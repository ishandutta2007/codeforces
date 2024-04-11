#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int arr[2020200];
int arr2[2020200];
int dp[2020200];

int main()
{
    int a,b,x,y,z,i,j,k,l,m,n;
    ll hap=0,sum=0,ans=0,cnt=0,chk=0;
    scanf("%d",&n);
    for(i=1;i<=n*2;i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+1+2*n);
    for(i=1;i<=n;i++)
        sum+=arr[i];
    for(i=n+1;i<=n*2;i++)
        hap+=arr[i];
    if(sum==hap)
        printf("-1");
    else
        for(i=1;i<=2*n;i++)
            printf("%d ",arr[i]);
}