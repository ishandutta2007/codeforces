#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int arr[2020200];
int arr2[2020200];
int dp[2020200];

int main()
{
    int a=0,b=0,x,y,z,i,j,k,l,m,n,q=0;
    int deg=0;
    scanf("%d %d",&n,&x);
    for(i=1;i< 1<<n ;i++)
    {
        if(i==x) continue;
        if(dp[i]==1) continue;
        deg++;
        arr[deg]=i;
        //printf("%d\n",arr[deg]);
        dp[i^x]=1;
    }
    printf("%d\n",deg);
    for(i=1;i<=deg;i++)
    {
        printf("%d ",arr[i]^arr[i-1]);
    }
}