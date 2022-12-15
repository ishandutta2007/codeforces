#include<iostream>

using namespace std;

long long dp[100001];
bool b[100001];
long long a[100001];

int main ()
{
    int n,x,i;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;
        a[x]++;
    }

    dp[1]=a[1];

    for(i=2;i<=100000;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]*i);
    }

    cout<<dp[100000]<<endl;

    return 0;
}