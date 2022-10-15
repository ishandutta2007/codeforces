#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int t,cnt[16],comb[15][15];
ll dp[20][10];
ll k;
ll get_ans(int n)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(!dp[i][j]) continue;
            for(int k=0;k<=min(cnt[i],n-j);k++) dp[i+1][j+k]+=dp[i][j]*comb[n-j][k];
        }
    }
    return dp[16][n];
}
int main()
{
    comb[0][0]=1;
    for(int i=1;i<=10;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++) comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    }
    scanf("%lld%d",&k,&t);
    for(int i=0;i<16;i++) cnt[i]=t;
    int d=1;
    for(;;)
    {
        ll res=get_ans(d);
        cnt[0]--; res-=get_ans(d-1);
        cnt[0]++;
        if(res>=k) break;
        else
        {
            k-=res;
            d++;
        }
    }
    assert(d<=9);
    for(int i=1;i<=d;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(!cnt[j]) continue;
            if(i==1&&j==0) continue;
            cnt[j]--;
            ll res=get_ans(d-i);
            if(res>=k)
            {
                printf("%c",j<10?'0'+j:'a'+j-10);
                break;
            }
            else
            {
                cnt[j]++;
                k-=res;
            }
        }
    }
    return 0;
}