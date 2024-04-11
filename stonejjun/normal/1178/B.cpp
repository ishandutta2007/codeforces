#include<bits/stdc++.h>
using namespace std;

char c[1010101];
long long int arr[1010101];
int arr2[1010101];
int dp[1010101];

int main()
{
    long long int i,j,k,l,m,n,cnt=0,hap=0,vcnt=0;
    long long int ans=0;
    scanf("%s",&c);
    int len=strlen(c);
    for(i=0;i<len;i++)
    {
        if(c[i]=='v'&&c[i+1]=='v')
        {
            arr[i]=1;
            vcnt++;
        }
    }
    for(i=0;i<len;i++)
    {
        if(arr[i]==1) cnt++;
        if(c[i]=='o')
        {
            ans+=cnt*(vcnt-cnt);
        }
    }
    printf("%lld",ans);
}