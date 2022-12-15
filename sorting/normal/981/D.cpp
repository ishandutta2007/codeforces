#include<iostream>

using namespace std;

bool dp[55][55][62];
bool b[55][55][62];
long long pr=61,n,k;
long long a[62];
long long prefix[62];
long long res;

bool have(long long l,long long r,long long bit)
{
    long long sum,t;

    if(l==0)
        sum=prefix[r];
    else
        sum=prefix[r]-prefix[l-1];

    //cout<<sum<<" "<<l<<" sum a "<<r<<endl;

    t=(long long)1;
    t<<=bit;

    if(res!=0)
        if((sum&res)!=res)
            return 0;

    return (sum&t);
}

bool solve(long long i,long long j,long long bit)
{
    //cout<<i<<" "<<j<<" "<<bit<<endl;

    if(j==k)
    {
        if(i==n)
            return 1;
        return 0;
    }
    if(i==n)
        return 0;
    if(b[i][j][bit])
        return dp[i][j][bit];

    b[i][j][bit]=1;

    long long ind;

    dp[i][j][bit]=0;

    for(ind=i;ind<n;ind++)
    {
        if(have(i,ind,bit))
            if(solve(ind+1,j+1,bit))
                dp[i][j][bit]=1;
    }

    //cout<<dp[i][j][bit]<<" "<<i<<" "<<j<<" "<<bit<<endl;

    return dp[i][j][bit];
}

int main ()
{
    long long i,j,r;
    bool boo;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
        for(j=0;j<k;j++)
        {
            //if(n-i>=k-j)
                dp[i][j][61]=1;

            b[i][j][61]=1;
        }

    prefix[0]=a[0];
    for(i=1;i<n;i++)
        prefix[i]=prefix[i-1]+a[i];

    for(i=60;i>=0;i--)
    {
        boo=solve(0,0,i);
        //cout<<boo<<" "<<i<<endl;
        if(boo)
        {
            r=(long long )1;
            r<<=i;
            res+=r;
        }
    }

    cout<<res<<endl;

    return 0;
}
/*
7 3
1 1 1 1 1 1 1
*/