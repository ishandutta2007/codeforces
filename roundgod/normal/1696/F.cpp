#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str[MAXN][MAXN];
int d[MAXN][MAXN];
bool construct(vector<int> &v)
{
    if(v.size()==1) return true;
    if(v.size()==2)
    {
        d[v[0]][v[1]]=d[v[1]][v[0]]=1;
        return true;
    }
    int sz=(int)v.size();
    P p=P(INF,-1);
    for(int i=0;i<sz;i++)
    {
        int x=v[i],cnt=0;
        bool f=true;
        for(int j=0;j<sz;j++)
        {
            if(j==i) continue;
            int y=v[j];
            for(int k=j+1;k<sz;k++)
            {
                if(k==i) continue;
                int z=v[k];
                if(str[min(y,z)][max(y,z)][x-1]=='1') cnt++;
            }
        }
        p=min(p,P(cnt,x));
    }
    int leaf=p.S;
    if(leaf==-1) return false;
    //printf("leaf=%d\n",leaf);
    vector<int> tmp;
    for(auto x:v) if(x==leaf) continue; else tmp.push_back(x);
    if(!construct(tmp)) return false;
    for(int i=0;i<sz;i++)
    {
        if(v[i]==leaf) continue;
        int x=v[i];
        for(int j=i+1;j<sz;j++)
        {
            if(v[j]==leaf) continue;
            int y=v[j];
            if(d[x][y]==1)
            {
                if(str[min(leaf,y)][max(leaf,y)][x-1]=='1')
                {
                    d[leaf][x]=d[x][leaf]=1;
                    //printf("add edge %d %d\n",x,leaf);
                    return true;
                }
                else if(str[min(leaf,x)][max(leaf,x)][y-1]=='1')
                {
                    d[leaf][y]=d[y][leaf]=1;
                    //printf("add edge %d %d\n",y,leaf);
                    return true;
                }
            }
        }
    }
    return false;
}
bool check()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(d[i][j]==INF) return false;
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                int x=(d[i][k]==d[j][k]?1:0);
                int y=(str[i][j][k-1]-'0');
                if(x!=y) return false;
            }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=(i==j?0:INF);
        for(int i=1;i<=n-1;i++)
            for(int j=1;j<=n-i;j++)
                cin>>str[i][i+j];
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        if(!construct(v)) {puts("No"); continue;}
        if(!check()) {puts("No"); continue;}
        puts("Yes");
        int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(d[i][j]==1) {printf("%d %d\n",i,j); cnt++;}
        assert(cnt==n-1);
    }
    return 0;
}