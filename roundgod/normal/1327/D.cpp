#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,x,y,ans;
int p[MAXN],c[MAXN];
bool vis[MAXN];
vector<int> v;
void check(int n,int d)
{
    for(int i=0;i<d;i++)
    {
        bool f=true;
        int cc=-1;
        for(int j=i;j<n;j+=d) 
        {
            if(cc==-1) cc=v[j];
            else if(v[j]!=cc) {f=false; break;}
        }
        if(f) {ans=min(ans,d); return;}
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=INF;
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                v.clear();
                int now=i;
                do
                {
                    vis[now]=true;
                    v.push_back(c[now]);
                    now=p[now];
                }while(now!=i);
                int m=(int)v.size();
                for(int j=1;j*j<=m;j++)
                {
                    if(m%j) continue;
                    check(m,j); 
                    if(j*j!=m) check(m,m/j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}