#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l[MAXN],r[MAXN],c[MAXN];
map<P,int> mp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&l[i],&r[i],&c[i]);
        int lid=0,rid=0;
        for(int i=1;i<=n;i++)
        {
            if(!mp.count(P(l[i],r[i]))) mp[P(l[i],r[i])]=c[i]; else mp[P(l[i],r[i])]=min(mp[P(l[i],r[i])],c[i]);
            if(lid==0||l[i]<l[lid]||(l[i]==l[lid]&&c[i]<c[lid])) lid=i;
            if(rid==0||r[i]>r[rid]||(r[i]==r[rid]&&c[i]<c[rid])) rid=i;
            int ans=c[lid]+c[rid];
            if(mp.count(P(l[lid],r[rid]))) ans=min(ans,mp[P(l[lid],r[rid])]);
            printf("%d\n",ans);
        }
    }
    return 0;
}