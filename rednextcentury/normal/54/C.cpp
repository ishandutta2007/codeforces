#include<bits/stdc++.h>
using namespace std;
long double prob[10000];
long double dp[1001][1001];
int cur[10000];
int a[100000];
long long pw[1000000];
long long solve(long long x)
{
    if (x==0)return 0;
    int p=0;
    while(x)
    {
        a[p++]=x%10;
        x/=10;
    }
    if (a[p-1]==1)
    {
        long long ans=(pw[p-1]-1)/9;
        long long num=0;
        for (int i=p-2;i>=0;i--)
            num=num*10+a[i];
        return ans+num+1;
    }
    else
    {
        return (pw[p]-1)/9;
    }
}
void calc(int i,long long l,long long r)
{
    prob[i]=(solve(r)-solve(l-1))/((long double)(r-l+1));
}
int main()
{
    pw[0]=1;
    for (int i=1;i<=19;i++)
        pw[i]=pw[i-1]*10;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        long long l,r;
        cin>>l>>r;
        calc(i,l,r);
    }
    dp[0][0]=1-prob[0];
    dp[0][1]=prob[0];
    for (int i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]*(1-prob[i]);
        for (int j=1;j<=n;j++)
            dp[i][j]=dp[i-1][j]*(1-prob[i])+dp[i-1][j-1]*prob[i];
    }
    int k;
    cin>>k;
    long double ret=0;
    for (int i=0;i<=n;i++)
    {
        if ((i*100)/n >= k)
            ret+=dp[n-1][i];
    }
    cout<<setprecision(10)<<fixed<<ret<<endl;
}