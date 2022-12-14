#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int sum[5][5];
int can[5][5];
int  mn[5][5];
int num[5][5];
int dp[6][(1<<15)][6];
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int c1,v,c2;
        cin>>c1>>v>>c2;
        if (c1>c2)swap(c1,c2);
        if (mn[c1][c2]==0 || v<mn[c1][c2])
            mn[c1][c2]=v;
        sum[c1][c2]+=v;
        num[c1][c2]++;
        num[c1][c2]%=2;
    }

        num[1][1]=num[2][2]=num[3][3]=num[4][4]=1;
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            can[i][j]=sum[i][j]-(1-num[i][j])*mn[i][j];
    pair<int,int> op[12];
    int tot=0;
    for (int i=1;i<=4;i++)
        for (int j=i;j<=4;j++)
            if (can[i][j]!=0)
                op[tot++]={i,j};
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            dp[i][0][j]=-1e9;
    dp[1][0][1]=0;
    dp[2][0][2]=0;
    dp[3][0][3]=0;
    dp[4][0][4]=0;
    int N=(1<<tot);
    for (int ranoutofnames=1;ranoutofnames<=4;ranoutofnames++)
    {
        for (int i=1;i<N;i++)
        {
            for (int j=1;j<=4;j++)
            {
                dp[ranoutofnames][i][j]=-1e9;
                for (int x=0;x<tot;x++)
                {
                    if (j!=op[x].first && j!=op[x].second)
                        continue;
                    if ((i&(1<<x))==0)
                        continue;
                    if (can[op[x].first][op[x].second]==0)
                        continue;
                    int was;
                    if (op[x].first==j)
                        was=op[x].second;
                    else
                        was=op[x].first;
                    dp[ranoutofnames][i][j]=max(dp[ranoutofnames][i-(1<<x)][was]+can[op[x].first][op[x].second],dp[ranoutofnames][i][j]);
                }
            }
        }
    }
    int ret=0;
    for (int i=0;i<tot;i++)
        ret=max(ret,sum[op[i].first][op[i].second]);
    for (int i=1;i<N;i++)
    {
        int add=0;
        int has[5]={0};
        for (int j=0;j<tot;j++)
        {
            if ((i&(1<<j)))
            {
                has[op[j].first]=1;
                has[op[j].second]=1;
            }
        }
        bool vis[20]={0};
        for (int l=0;l<20;l++)
        {
            for (int j=0;j<tot;j++)
            {
                if (has[op[j].first] || has[op[j].second])
                {
                    if (!vis[j] && ((1<<j)&i) ==0)
                        vis[j]=1,has[op[j].first]=1,has[op[j].second]=1,add+=sum[op[j].first][op[j].second]-num[op[j].first][op[j].second]*mn[op[j].first][op[j].second];
                }
            }
        }
        int cur=0;
        int taken = -1;
        for (int j=1;j<=4;j++)
        {
            for (int l=1;l<=4;l++)
            {
                int add2=0;
                for (int x=0;x<tot;x++)
                {
                    if ((1<<x)&i && num[op[x].first][op[x].second]==0 && (op[x].first==j || op[x].second==j))
                        if (mn[op[x].first][op[x].second]>add2)
                            add2=mn[op[x].first][op[x].second],taken=x;
                }
                int add3=0;
                for (int x=0;x<tot;x++)
                {
                    if (taken!=x && (1<<x)&i && num[op[x].first][op[x].second]==0 && (op[x].first==l || op[x].second==l))
                        add3=max(add3,mn[op[x].first][op[x].second]);
                }
                cur=max(cur,dp[l][i][j]+add2+add3);
            }
        }
        ret=max(ret,cur+add);
    }
    cout<<ret<<endl;
}