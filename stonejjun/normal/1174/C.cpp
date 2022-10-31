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
    int deg=0;
    ll hap=0,sum=0,ans=0,cnt=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        int chk=1;
        for(j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                chk=0;
            }
        }
        if(chk==1)
        {
            deg++;
            arr[deg]=i;
        }
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=deg;j++)
        {
            if(i%arr[j]==0)
            {
                dp[i]=j;
                break;
            }
        }
    }


    for(i=2;i<=n;i++)
        printf("%d ",dp[i]);
}