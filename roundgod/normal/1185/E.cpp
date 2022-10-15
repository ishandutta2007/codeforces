#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define x1 saokfdsao
#define y1 dspaodqwpk
#define x2 dsoakdsao
#define y2 asokdoasd
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int T,n,m;
char mp[MAXN][MAXN];
char draw[MAXN][MAXN];
int fx,fy;
int xmin[26],xmax[26],ymin[26],ymax[26];
struct node
{
    int x1,y1,x2,y2;
};
vector<node> ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
        int tot=-1;
        for(int i=0;i<26;i++) xmin[i]=ymin[i]=INF,xmax[i]=ymax[i]=-INF;
        bool f=true;
        int maxi=-1;
        fx=fy=-1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(mp[i][j]!='.') 
                {
                    int id=mp[i][j]-'a';
                    tot=max(tot,id);
                    xmin[id]=min(xmin[id],i);
                    ymin[id]=min(ymin[id],j);
                    xmax[id]=max(xmax[id],i);
                    ymax[id]=max(ymax[id],j);
                    if(id>maxi)
                    {
                        maxi=id;
                        fx=i;
                        fy=j;
                    }
                }
        if(tot==-1)
        {
            puts("YES");
            puts("0");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                draw[i][j]='.';
        for(int i=0;i<=tot;i++)
        {
            if(xmin[i]==INF)
            {
                ans.push_back((node){fx,fy,fx,fy});
                continue;
            }
            if(ymax[i]-ymin[i]>0&&xmax[i]-xmin[i]>0)
            {
                f=false;
                break;
            }
            else if(xmin[i]==xmax[i])
            {
                ans.push_back((node){xmin[i],ymin[i],xmax[i],ymax[i]});
                for(int j=ymin[i];j<=ymax[i];j++)
                    draw[xmin[i]][j]=(char)('a'+i);
            }
            else
            {
                ans.push_back((node){xmin[i],ymin[i],xmax[i],ymax[i]});
                for(int j=xmin[i];j<=xmax[i];j++)
                    draw[j][ymin[i]]=(char)('a'+i);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(mp[i][j]!=draw[i][j])
                {
                    f=false;
                    break;
                }
        if(!f) puts("NO");
        else
        {
            puts("YES");
            printf("%d\n",(int)ans.size());
            for(auto p:ans) printf("%d %d %d %d\n",p.x1,p.y1,p.x2,p.y2);
        }
    }
    return 0;
}