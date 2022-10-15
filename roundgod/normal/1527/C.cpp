#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> dis;
vector<int> pos[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        dis.clear();
        for(int i=1;i<=n;i++) pos[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            dis.push_back(a[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        ll ans=0;
        for(int i=1;i<=n;i++) pos[a[i]].push_back(i);
        for(int i=1;i<=n;i++)
        {
            ll s=0;
            for(auto x:pos[i])
            {
                ans+=(n+1-x)*s;
                s+=x;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}