#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N;
const int MN = 200010;
vector<int>e[MN];
int col[MN];
LL cnt[MN][2];
LL sum[MN][2];
LL sumdif = 0, sumsam = 0;

void dfs(int x,int fa)
{
    col[x] = col[fa] ^ 1;
    cnt[x][col[x]] = 1;
    cnt[x][col[x] ^ 1] = 0;
    sum[x][0] = sum[x][1] = 0;
    for (auto t:e[x])
        if (t != fa)
        {
            dfs(t,x);
            sumdif += cnt[t][0] * sum[x][1] + sum[t][0] * cnt[x][1] + cnt[x][1] * cnt[t][0];
            sumdif += cnt[t][1] * sum[x][0] + sum[t][1] * cnt[x][0] + cnt[x][0] * cnt[t][1];
            sumsam += cnt[t][0] * sum[x][0] + sum[t][0] * cnt[x][0] + cnt[x][0] * cnt[t][0];
            sumsam += cnt[t][1] * sum[x][1] + sum[t][1] * cnt[x][1] + cnt[x][1] * cnt[t][1];
            cnt[x][0] += cnt[t][0];
            cnt[x][1] += cnt[t][1];
            sum[x][0] += sum[t][0] + cnt[t][0];
            sum[x][1] += sum[t][1] + cnt[t][1];
        }
    //printf("cnt[%d][0]=%lld cnt[%d][1]=%lld sum[%d][0]=%lld sum[%d][1]=%lld\n",x,cnt[x][0],x,cnt[x][1],x,sum[x][0],x,sum[x][1]);
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<N;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int cc[2];
    cc[0] = cc[1] = 0;
    for (int i=1;i<=N;i++)cc[col[i]]++;

    //printf("%lld %lld\n",sumsam,sumdif);
    printf("%lld\n", sumsam / 2 + (sumdif + 1LL*cc[0]*cc[1]) / 2);
}