#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1048576 + 11;

int a[N];
ll d[21];
ll dd[21][21];
ll ddd[21][N];
ll dp[N];

void rec(int i, ll sum, int pos, int mask)
{
    if (pos==21)
    {
        ddd[i][mask]=sum;
        return;
    }
    rec(i,sum-dd[i][pos],pos+1,mask+(1<<(pos-1)));
    rec(i,sum,pos+1,mask);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=1; i<=20; i++)
    {
        int pos=1;
        for (int j=1; j<=n; j++)
            if (a[j]==i) {d[i]+=1ll*(j-pos); pos++;}
        int kk=0;
        for (int j=n; j>=1; j--)
            if (a[j]==i) kk++; else
        {
            dd[i][a[j]]+=kk;
        }
        rec(i,d[i],1,0);
    }
    dp[0]=0;
    for (int j=1; j<=(1<<20); j++)
        dp[j]=2e18;
    for (int mask=0; mask<(1<<20); mask++)
    for (int i=1; i<=20; i++)
        if ((mask&(1<<(i-1)))==0)
    {
        dp[(mask^(1<<(i-1)))]=min(dp[(mask^(1<<(i-1)))],
                    dp[mask]+ddd[i][mask]);
    }
    cout<<dp[(1<<20)-1];
}