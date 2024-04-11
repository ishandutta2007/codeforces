#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot=1,n,k;
int trie[MAXN][10];
int ans,cnt[MAXN];
vector<int> child[MAXN];
char str[MAXN];
int f[MAXN][MAXN][11],g[MAXN][10][MAXN][11];
void insert(char *s,int rt,int num)
{
    for(int i=0;s[i];i++)
    {
        int x=s[i]-'0';
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
    }
    cnt[rt]+=num;
}
void dfs(int v,int d)
{
    for(int i=0;i<10;i++) 
        if(trie[v][i]) 
        {
            dfs(trie[v][i],d+1);
            child[v].push_back(trie[v][i]);
        }
    if(!child[v].size())
    {
        for(int fa=0;fa<=d;fa++)
            for(int i=0;i<=k;i++)
                f[v][fa][i]=(i?0:cnt[v]*(d-fa));
    }
    else
    {
        int sz=(int)child[v].size();
        for(int fa=d;fa>=0;fa--)
            for(int i=0;i<=k;i++)
                g[v][0][fa][i]=f[child[v][0]][fa][i];
        for(int num=1;num<sz;num++)
            for(int fa=d;fa>=0;fa--)
                for(int i=0;i<=k;i++)
                {
                    g[v][num][fa][i]=INF;
                    int to=child[v][num];
                    for(int choose=0;choose<=i;choose++)
                        g[v][num][fa][i]=min(g[v][num][fa][i],g[v][num-1][fa][i-choose]+f[to][fa][choose]);
                }
        for(int fa=d;fa>=0;fa--)
        {
            for(int i=0;i<=k;i++)
            {
                f[v][fa][i]=g[v][sz-1][fa][i]+cnt[v]*(d-fa);
                if(i) f[v][fa][i]=min(f[v][fa][i],g[v][sz-1][d][i-1]);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int x;
        scanf("%d",&x);
        insert(str,1,x);
    }
    dfs(1,0);
    printf("%d\n",f[1][0][k]);
    return 0;
}