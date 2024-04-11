#include<iostream>
#define MOD 1000000007

using namespace std;

int k;
long long  dp[101][101];
bool b[101][101];

long long solve(int n,int d)
{
    //cout<<n<<" "<<d<<endl;

    if(n<0)return 0;
    if(n==0)
    {
        if(d==0)return 1;
        else return 0;
    }
    if(b[n][d])return dp[n][d];

    b[n][d]=1;
    long long& ans=dp[n][d];

    int i;

    for(i=1;i<d;i++)
    {
        ans+=solve(n-i,d);
        ans%=MOD;
    }
    for(i;i<=k;i++)
    {
        ans+=solve(n-i,0);
        ans%=MOD;
    }

    return ans;
}

int main ()
{
    int n,d;

    cin>>n>>k>>d;

    cout<<solve(n,d)<<endl;

    return 0;
}