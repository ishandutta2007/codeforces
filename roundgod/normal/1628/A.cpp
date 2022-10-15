#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<int> pos[MAXN];
vector<int> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n); ans.clear();
        for(int i=0;i<=n;i++) pos[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
        }
        for(int i=n;i>=1;i--) pos[a[i]].push_back(i);
        int now=1;
        while(now<=n)
        {
            int mex=0,npos=now+1;
            for(int i=0;i<=n;i++)
            {
                while(pos[i].size()&&pos[i].back()<now) pos[i].pop_back();
                if(pos[i].size())
                {
                    mex++;
                    npos=max(npos,pos[i].back()+1);
                }
                else break;
            }
            ans.push_back(mex);
            now=npos;
        }
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}