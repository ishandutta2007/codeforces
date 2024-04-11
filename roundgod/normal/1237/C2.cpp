#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN],z[MAXN];
vector<int> xx[MAXN];
vector<int> yy[MAXN];
bool used[MAXN];
vector<int> vx,vy,vz;
bool cmp(int i,int j)
{
    return z[i]<z[j];
}
bool cmp2(int i,int j)
{
    return x[i]<x[j];
}
void solve_surface(int xid)
{
    vector<int> dy; dy.clear();
    for(auto id:xx[xid])
    {
        yy[y[id]].push_back(id);
        dy.push_back(y[id]);
    }
    sort(dy.begin(),dy.end());
    dy.erase(unique(dy.begin(),dy.end()),dy.end());
    for(auto ind:dy)
    {
        sort(yy[ind].begin(),yy[ind].end(),cmp);
        while(yy[ind].size()>=2)
        {
            int id1=yy[ind].back(); yy[ind].pop_back();
            int id2=yy[ind].back(); yy[ind].pop_back();
            printf("%d %d\n",id1,id2);
            used[id1]=used[id2]=true;
        }
    }
    vector<int> vv; vv.clear();
    for(auto ind:dy)
        for(auto id:yy[ind]) vv.push_back(id);
    while(vv.size()>=2)
    {
        int id1=vv.back(); vv.pop_back();
        int id2=vv.back(); vv.pop_back();
        printf("%d %d\n",id1,id2);
        used[id1]=used[id2]=true;
    }
    for(auto id:xx[xid]) yy[y[id]].clear();
}
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        vx.push_back(x[i]); vy.push_back(y[i]);
        vz.push_back(z[i]);
    }
    sort(vx.begin(),vx.end()); sort(vy.begin(),vy.end()); sort(vz.begin(),vz.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    vy.erase(unique(vy.begin(),vy.end()),vy.end());
    vz.erase(unique(vz.begin(),vz.end()),vz.end());
    for(int i=1;i<=n;i++)
    {
        x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin()+1;
        y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin()+1;
        z[i]=lower_bound(vz.begin(),vz.end(),z[i])-vz.begin()+1;
        xx[x[i]].push_back(i);
    }
    for(int i=1;i<=50000;i++) if(xx[i].size()) solve_surface(i);
    vector<int> vv; vv.clear();
    for(int i=1;i<=50000;i++)
    {
        while(xx[i].size())
        {
            int id=xx[i].back();
            if(!used[id]) vv.push_back(id);
            xx[i].pop_back();
        }
    }
    while(vv.size()>=2)
    {
        int id1=vv.back(); vv.pop_back();
        int id2=vv.back(); vv.pop_back();
        printf("%d %d\n",id1,id2);
        used[id1]=used[id2]=true;
    }
    return 0;
}