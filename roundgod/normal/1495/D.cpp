#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,curi,d[MAXN][MAXN];
vector<int> fp[MAXN],gp[MAXN];
bool valid[MAXN];
int inv[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
vector<P> E;
bool cmp(int x,int y)
{
    return d[curi][x]<d[curi][y];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    inv[1]=1;
	for(int i=2;i<=400;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        E.push_back(P(x,y));
        d[x][y]=d[y][x]=1;
    }
    floyd_warshall();
    for(int i=1;i<=n;i++)
    {
        curi=i;
        for(int j=1;j<=n;j++)
        {
            memset(valid,false,sizeof(valid));
            for(int k=1;k<=n;k++) fp[k].clear(),gp[k].clear();
            int cnt=0;
            for(int k=1;k<=n;k++) if(d[i][k]+d[j][k]==d[i][j]) {valid[k]=true; cnt++;}
            if(cnt!=d[i][j]+1)
            {
                printf("0 ");
                continue;
            }
            for(auto p:E)
            {
                if(max(d[i][p.F]-d[i][p.S],d[i][p.S]-d[i][p.F])!=1||max(d[j][p.F]-d[j][p.S],d[j][p.S]-d[j][p.F])!=1) continue;
                P q=p;
                if(d[i][q.F]>d[i][q.S]) swap(q.F,q.S);
                if(d[j][q.F]>d[j][q.S]) gp[q.S].push_back(q.F);
                else fp[q.S].push_back(q.F);
            }
            int res=1;
            for(int k=1;k<=n;k++) if(!valid[k]) res=1LL*res*(int)fp[k].size()%MOD;
            printf("%d ",res);
        }
        puts("");
    }
    return 0;
}