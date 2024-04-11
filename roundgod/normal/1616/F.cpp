#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int t,n,m;
map<P,int> mp;
vector<vector<int> > f;
vector<int> g;
int color[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        f.clear(); g.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) color[i]=0;
        mp.clear();
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w); w--;
            if(u>v) swap(u,v);
            mp[P(u,v)]=i;
            if(w!=-2) 
            {
                f.emplace_back(m);
                f.back()[i]=1;
                g.push_back(w);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(!mp.count(P(i,j))) continue;
                for(int k=j+1;k<=n;k++)
                {
                    if(!mp.count(P(j,k))||!mp.count(P(i,k))) continue;
                    f.emplace_back(m);
                    f.back()[mp[P(i,j)]]=f.back()[mp[P(j,k)]]=f.back()[mp[P(i,k)]]=1;
                    g.push_back(0);
                }
            }
        int r=0;
        for(int i=0;i<m;i++)
        {
            int pos=r;
            while(pos<(int)f.size()&&!f[pos][i]) pos++;
            if(pos==(int)f.size()) continue;
            swap(f[pos],f[r]); swap(g[pos],g[r]);
            if(f[r][i]==2)
            {
                for(int j=i;j<m;j++) f[r][j]=(3-f[r][j])%3;
                g[r]=(3-g[r])%3;
            }
            for(int j=0;j<(int)f.size();j++)
            {
                if(f[j][i]!=0&&j!=r)
                {
                    int v=f[j][i];
                    for(int k=i;k<m;k++)
                    {
                        f[j][k]=(f[j][k]-v*f[r][k])%3; 
                        if(f[j][k]<0) f[j][k]+=3;
                    }
                    g[j]=(g[j]-v*g[r])%3; if(g[j]<0) g[j]+=3;
                }
            }
            r++;
        }
        bool flag=true;
        for(int i=r;i<(int)f.size();i++) 
        {
            if(g[i])
            {
                puts("-1");
                flag=false; break;
            }
        }
        if(!flag) continue; 
        for(int i=r-1;i>=0;i--)
        {
            int j=0;
            while(!f[i][j]) j++;
            color[j]=g[i];
        }
        for(int i=0;i<m;i++) printf("%d ",color[i]+1);
        puts("");
    }
    return 0;
}