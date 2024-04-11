#include<iostream>

using namespace std;

const long long mod=998244353;

long long a[1009];

long long n,sum;

long long dp[1009][1009];
bool b[1009][1009];

long long solve(long long curr,long long left)
{
    if(curr==n+1 && left==0)
        return 1;
    if(curr>=n+1)
        return 0;
    if(left==0)
    {
        if(a[curr]<=0 || a[curr]+curr>n)
            return 0;


        left=a[curr]+1;
    }

    if(b[curr][left])
        return dp[curr][left];

    b[curr][left]=1;

    dp[curr][left]+=solve(curr+1,left)+solve(curr+1,left-1);

    dp[curr][left]%=mod;

    return dp[curr][left];
}


int main ()
{
    long long i,res=0,p;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>a[i];

    //update(n+1,1);

    //cout<<"hi"<<endl;

    for(i=n;i>=1;i--)
    {
        //cout<<i<<" i"<<endl;
        res+=solve(i,0);
        res%=mod;
    }

    while(res<0)
        res+=mod;

    cout<<res<<endl;

    return 0;
}