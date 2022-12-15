#include<iostream>

using namespace std;

int mod=1000000007;

int sum;
int dp[2][200001];

int main ()
{
    int r,g,i,realR;
    int used;

    cin>>r>>g;

    sum=r+g;

    for(i=1;i*(i+1)/2<=sum;i++)
        continue;

    //i--;

    realR=r;

    //cout<<solve(1,r)<<endl;

    for(int level=i;level>=1;level--)
    {
        for(r=0;r<=realR;r++)
        {
            int used=level*(level-1)/2;

            dp[level%2][r]=0;

            if(sum-used<level)
            {
                dp[level%2][r]=1;
                //cout<<dp[level%2][r]<<" "<<level<<" "<<r<<endl;
                continue;
            }
            if(r<level && sum-used-r<level)
            {
                dp[level%2][r]=0;
                //cout<<dp[level%2][r]<<" "<<level<<" "<<r<<endl;
                continue;
            }

            if(r>=level)
            {
                dp[level%2][r]+=dp[(level+1)%2][r-level];
                dp[level%2][r]%=mod;
            }
            if(sum-used-r>=level)
            {
                dp[level%2][r]+=dp[(level+1)%2][r];
                dp[level%2][r]%=mod;
            }

            //cout<<dp[level%2][r]<<" "<<level<<" "<<r<<endl;
        }
        //cout<<dp[level][r]<<" = "<<level<<" "<<r<<endl;
    }

    //cout<<realR<<endl;

    cout<<dp[1][realR]<<endl;

    return 0;
}