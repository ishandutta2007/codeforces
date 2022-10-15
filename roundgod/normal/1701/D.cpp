#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],ans[MAXN];
vector<P> v[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            int l,r;
            if(a[i]==0) {l=i+1; r=n;}
            else
            {
                l=(i/(a[i]+1))+1; r=(i/a[i]);
            }
            v[r].push_back(P(l,i));
        }
        set<P> s;
        for(int i=n;i>=1;i--)
        {
            for(auto p:v[i]) s.insert(p);
            auto p=*(--s.end());
            s.erase(--s.end());
            ans[p.S]=i;
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}