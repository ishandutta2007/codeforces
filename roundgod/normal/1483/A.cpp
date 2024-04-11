#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> v[MAXN];
int rem[MAXN],ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) v[i].clear();
        for(int i=1;i<=n;i++) rem[i]=(m+1)/2;
        bool f=true;
        for(int i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
            }
            if(k==1)
            {
                ans[i]=v[i][0];
                if(!rem[v[i][0]]) f=false;
                rem[v[i][0]]--;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if((int)v[i].size()==1) continue;
            int res=-INF,id=0;
            for(auto x:v[i])
            {
                if(rem[x]>res)
                {
                    res=rem[x];
                    id=x;
                }
            }
            if(!rem[id]) f=false;
            ans[i]=id; rem[id]--;
        }
        if(!f) puts("NO");
        else
        {
            puts("YES");
            for(int i=1;i<=m;i++) printf("%d%c",ans[i],i==m?'\n':' ');
        }
    }
    return 0;
}