#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int arr[2020200];
int arr2[2020200];
int dp[2020200];

int main()
{
    int a=0,b=0,x,y,z,i,j,k,l,m,n;
    ll hap=0,sum=0,ans=0,cnt=0,chk=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%2==0)
            a++;
        else b++;
    }
    if(a!=0&&b!=0)
    {
        sort(arr+1,arr+1+n);
        for(i=1;i<=n;i++)
            printf("%d ",arr[i]);
        return 0;
    }
    for(i=1;i<=n;i++)
        printf("%d ",arr[i]);
}