#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 20
#define MAXM (1<<20)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int cnt[MAXN][MAXN];
int dp[MAXM];
string str;
int main()
{
    scanf("%d%d",&n,&m);
    cin>>str;
    for(int i=1;i<n;i++)
    {
        int x=str[i]-'a',y=str[i-1]-'a';
        if(x==y) continue;
        cnt[x][y]++; cnt[y][x]++;
    }
    for(int mask=0;mask<(1<<m);mask++) dp[mask]=INF;
    dp[0]=0;
    for(int mask=0;mask<(1<<m);mask++)
    {
        int d=__builtin_popcount(mask);
        for(int j=0;j<m;j++)
        {
            if(mask&(1<<j)) continue;
            int sum=0;
            for(int k=0;k<m;k++)
            {
                if(!(mask&(1<<k))) sum-=cnt[j][k];
                else sum+=cnt[j][k];
            }
            dp[mask^(1<<j)]=min(dp[mask^(1<<j)],dp[mask]+sum*d);
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
    return 0;
}