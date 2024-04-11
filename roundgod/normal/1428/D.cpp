#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],tot;
vector<P> indices;
vector<P> id[4];
int get_id()
{
    return tot--;
}
int main()
{
    scanf("%d",&n);
    int cnt2=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int s=0;
    bool f=true;
    if(!f)
    {
        puts("-1");
        return 0;
    }
    tot=n;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==0) continue;
        if(a[i]==1)
        {
            int x=get_id();
            id[1].push_back(P(x,i));
            indices.push_back(P(x,i));
        }
        else if(a[i]==2)
        {
            if(!id[1].size())
            {
                f=false;
                break;
            }
            else
            {
                P p=id[1].back(); id[1].pop_back();
                id[2].push_back(P(p.F,i));
                indices.push_back(P(p.F,i)); 
            }
        }
        else if(a[i]==3)
        {
            if(id[3].size())
            {
                P p=id[3].back(); id[3].pop_back();
                int x=get_id();
                id[3].push_back(P(x,i)); 
                indices.push_back(P(x,i)); indices.push_back(P(x,p.S));
            }
            else if(id[2].size())
            {
                P p=id[2].back(); id[2].pop_back();
                int x=get_id();
                id[3].push_back(P(x,i)); 
                indices.push_back(P(x,i)); indices.push_back(P(x,p.S));
            }
            else if(id[1].size())
            {
                P p=id[1].back(); id[1].pop_back();
                int x=get_id();
                id[3].push_back(P(x,i)); 
                indices.push_back(P(x,i)); indices.push_back(P(x,p.S));
            }
            else {f=false;  break;}
        }
    }
    if(!f) {puts("-1"); return 0;}
    printf("%d\n",(int)indices.size());
    for(auto p:indices) printf("%d %d\n",p.F,p.S);
    return 0;
}