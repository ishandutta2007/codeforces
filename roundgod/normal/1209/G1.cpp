#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,q;
int a[MAXN],l[MAXN],r[MAXN],cnt[MAXN];
struct node
{
    int l,r,tot;
};
vector<node> v;
bool cmp(node x,node y)
{
    return x.l<y.l;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=200000;i++) l[i]=INF,r[i]=-INF;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        l[a[i]]=min(l[a[i]],i);
        r[a[i]]=max(r[a[i]],i);
        cnt[a[i]]++;
    }
    for(int i=1;i<=200000;i++)
    {
        if(cnt[i])
        {
            v.push_back((node){l[i],r[i],cnt[i]});
        }
    }
    sort(v.begin(),v.end(),cmp);
    int curl=INF,curr=-1,ans=0,maxi=-INF;
    for(int i=0;i<(int)v.size();i++)
    {
        if(curl==INF)
        {
            curl=v[i].l;
            curr=v[i].r;
            maxi=v[i].tot;
        }
        else if(v[i].l>curr)
        {
            ans+=maxi;
            maxi=v[i].tot;
            curl=v[i].l;
            curr=v[i].r;
        }
        else
        {
            maxi=max(maxi,v[i].tot);
            curl=min(curl,v[i].l);
            curr=max(curr,v[i].r);
        }
    }
    if(maxi!=-INF) ans+=maxi;
    printf("%d\n",n-ans);
    return 0;
}