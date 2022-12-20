#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define endl "\n"

const int N = 707;

int a[N];
bool path[N][N];
bool dp[N][N][2];
bool b[N][N][2];

int n;

bool solve(int mini,int maxi,bool which)
{
    int i;

    if(maxi==mini+1)
        return 1;

    if(b[mini][maxi][which])
        return dp[mini][maxi][which];

    b[mini][maxi][which]=1;

    int curr;

    if(which==0)
        curr=mini;
    else
        curr=maxi;

    for(i=mini+1;i<maxi;i++)
    {
        if(!path[i][curr])
            continue;

        if(solve(i,maxi,0) && solve(mini,i,1))
        {
            dp[mini][maxi][which]=1;

            break;
        }
    }

    return dp[mini][maxi][which];
}

int main ()
{
    int i,j;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            if(__gcd(a[i],a[j])>1)
            {
                path[i][j]=1;
                path[j][i]=1;
            }
        }

    for(i=1;i<=n;i++)
    {
        if(solve(i,n+1,0) && solve(0,i,1))
        {
            cout<<"YES"<<endl;

            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;
}