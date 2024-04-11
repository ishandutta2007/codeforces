#include<iostream>

#define MOD 1000000007

using namespace std;

bool if_prime(long long p)
{
    for(long long i=2;i*i<=p;i++)
        if(p%i==0)return 0;

    return 1;
}

long long n;
long long f[3][71],arr[100002];
long long dp[2][1048576];
long long xorr[71];

int main ()
{
    long long i,j,st,k;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=1;i<=70;i++)
        f[0][i]=1;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        f[0][arr[i]]=f[1][arr[i]]=(f[0][arr[i]]+f[1][arr[i]])%MOD;
    }

    st=1;

    for(i=2;i<=70;i++)
    {
        if(!if_prime(i))continue;

        for(j=1;j<=70;j++)
        {
            k=j;

            while(k%i==0)
            {
                k/=i;

                xorr[j]^=st;
            }
        }

        st*=2;
    }

    //for(i=0;i<=70;i++)cout<<xorr[i]<<endl;

    dp[0][0]=1;

    for(i=1;i<=70;i++)
    {
        long long curr=i%2;
        long long prev=(i-1)%2;
        //cout<<i<<endl;
        for(j=0;j<1048576;j++)
        {
            dp[curr][j]=(dp[prev][j]*f[0][i]+dp[prev][j^xorr[i]]*f[1][i])%MOD;
            //if(f[0][i]==0)cout<<"NO "<<i<<" "<<j<<endl;
            //if(dp[i][j]>0)cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
        }
    }

    cout<<dp[0][0]-1<<endl;

    return 0;
}