#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
vector<int> v[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) has[i]=false;
        for(int i=1;i<=n;i++) v[i].clear();
        int id=-1;
        for(int i=1;i<=n;i++)
        {
            int m; scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int x; scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        for(int i=1;i<=n;i++)
        {
            bool f=false;
            for(auto x:v[i])
            {
                if(has[x]) continue;
                f=true; has[x]=true; break;
            }
            if(!f) id=i;
        }
        if(id==-1) puts("OPTIMAL");
        else
        {
            puts("IMPROVE");
            for(int i=1;i<=n;i++) 
                if(!has[i])
                {
                    printf("%d %d\n",id,i);
                    break;
                }
        }   
    }
    return 0;
}