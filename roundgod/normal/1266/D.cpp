#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
ll has[MAXN];
vector<int> a,b;
struct node
{
    int x,y;
    ll z;
};
vector<node> ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        has[x]-=z; has[y]+=z;
    }
    for(int i=1;i<=n;i++)
    {
        if(has[i]<0) a.push_back(i); else if(has[i]>0) b.push_back(i);
    }
    while(a.size()&&b.size())
    {
        int x=a.back(),y=b.back();
        ll z=min(-has[x],has[y]);
        if(z>0)
        {
            ans.push_back((node){x,y,z});
            has[x]+=z; has[y]-=z;
        }
        if(has[x]==0) a.pop_back();
        if(has[y]==0) b.pop_back();
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d %lld\n",p.x,p.y,p.z);
    return 0;
}