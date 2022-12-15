#include<iostream>

using namespace std;

const long long mod=1000000007;

long long dp[1001][1001][3];
bool b[1001][1001][3];
string s;

long long solve(long long pos,long long sum,bool eq)
{
    if(pos==s.size())
    {
        if(sum==0)
            return 1;
        return 0;
    }
    if(b[pos][sum][eq])
        return dp[pos][sum][eq];

    b[pos][sum][eq]=1;

    long long x=s[pos]-'0';
    long long i,r=eq?(x):1;
    bool newEq;

    for(i=0;i<=r;i++)
    {
        newEq=eq?(i==x):0;
        dp[pos][sum][eq]+=solve(pos+1,sum-i,newEq);
        dp[pos][sum][eq]%=mod;
    }

    return dp[pos][sum][eq];
}

long long sumDigits(long long x)
{
    long long i,res=0,p,one=1;

    for(i=0;x!=0;i++)
    {
        p=(long long)one<<i;
        if(x&p)
        {
            res++;
            x-=p;
        }
    }

    return res;
}

long long steps[1001];

int main ()
{
    long long k,i,res=0;

    cin>>s>>k;

    if(k==0)
    {
        cout<<"1"<<endl;
        return 0;
    }

    steps[1]=0;

    for(i=2;i<=1000;i++)
        steps[i]=steps[sumDigits(i)]+1;

    for(i=1;i<=1000;i++)
        if(steps[i]==k-1)
        {
            //cout<<i<<endl;
            res+=solve(0,i,1);
            if(i==1)res--;
            res%=mod;
        }

    cout<<res<<endl;

    return 0;
}