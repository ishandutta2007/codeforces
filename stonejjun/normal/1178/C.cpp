#include<bits/stdc++.h>
using namespace std;

char c[1010101];
long long int arr[1010101];
int arr2[1010101];
int dp[1010101];

int main()
{
    long long int a,b,i,j,k,l,m,n,cnt=0,hap=0,vcnt=0;
    long long int ans=1;
    scanf("%lld %lld",&a,&b);
    a+=b;
    for(i=1;i<=a;i++)
    {
        ans=ans*2;
        ans%=998244353;
    }
    printf("%lld",ans);
}