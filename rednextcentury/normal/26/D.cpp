#include <bits/stdc++.h>
using namespace std;
long double dp[2][2000001];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    dp[0][k]=1;
    int p=0;
    int center=0;
    int dir=1;
    if (m>n)dir=-1;
    center=k;
    int magic=900;
    for (int i=0;i<m;i++)
    {
        while(dp[p][center]<1e-7 && center<n+m && center+dir>=0)center+=dir;
        for (int j=max(0,center-magic/2);j<=center+magic;j++)
        {
            int ten = n-(i+j-k);
            int twenty = m-i;
            if (ten<0)break;
            dp[p][j+1]+=dp[p][j]*(ten/(ten+0.0+twenty));
            if (j>0)
                dp[!p][j-1]+=dp[p][j]*(twenty/(ten+0.0+twenty));
        }
        for (int j=max(0,center-magic/2);j<=center+magic;j++)
            dp[p][j]=0;
        p=!p;
    }
    long double ret=0;
    for (int j=max(0,center-magic);j<=center+magic;j++)ret+=dp[p][j];
    cout<<setprecision(8)<<fixed<<ret<<endl;
}