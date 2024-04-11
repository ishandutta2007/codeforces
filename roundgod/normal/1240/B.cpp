#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int q,n;
int a[MAXN];
vector<int> dis;
vector<int> pos[MAXN];
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        dis.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            dis.push_back(a[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        int sz=(int)dis.size();
        for(int i=1;i<=n;i++) pos[a[i]].push_back(i);
        int ans=1,st=1,now=1,cnt=1;
        while(st<=sz)
        {
            while(now<sz&&pos[now+1][0]>pos[now].back())
            {
                now++;
                cnt++;
            }
            ans=max(ans,cnt);
            st=now+1; now=st; cnt=1;
        }
        for(int i=1;i<=n;i++) pos[a[i]].clear();
        printf("%d\n",sz-ans);
    }
    return 0;
}