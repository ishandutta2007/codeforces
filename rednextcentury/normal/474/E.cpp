#include<bits/stdc++.h>
using namespace std;
#define L x*2
#define R L+1
#define mid (l+r)/2
long long a[1000000];
pair<int,int> tree[1000000];
pair<int,int> getMax(int x,int l,int r,int s,int e)
{
    if (s>e)return make_pair(0,0);
    if (l>e || r<s)
        return make_pair(0,0);
    if (l>=s && r<=e)
        return tree[x];
    return max(getMax(L,l,mid,s,e),getMax(R,mid+1,r,s,e));
}
void upd(int x,int l,int r,int v,pair<int,int> val)
{
    if (v<l || v>r)return;
    if (l==r)tree[x]=max(val,tree[x]);
    else upd(L,l,mid,v,val),upd(R,mid+1,r,v,val),tree[x]=max(tree[L],tree[R]);
}
int n;
long long k;
map<long long,int> to;
map<int,long long> from;
vector<long long> vec;
int tot=0;
int dp[1000000];
int b[1000000];
void PrintPath(int i)
{
    vector<int> ok;
    while(i!=0)
    {
        ok.push_back(i);
        i=b[i];
    }
    reverse(ok.begin(),ok.end());
    for (int i=0;i<ok.size();i++)
        cout<<ok[i]<<' ';
    cout<<endl;
}
int getLower(long long X)
{
    int l=1,r=tot;
    int ret=0;
    while(l<=r)
    {
        if (from[mid]<=X)
            ret=mid,l=mid+1;
        else
            r=mid-1;
    }
    return ret;
}
int getHigher(long long X)
{
    int l=1,r=tot;
    int ret=tot+1;
    while(l<=r)
    {
        if (from[mid]>=X)
            ret=mid,r=mid-1;
        else
            l=mid+1;
    }
    return ret;
}
void DP()
{
    int ret=0;
    int id=0;
    for (int i=1;i<=n;i++)
    {
        int l=getLower(a[i]-k);
        int r=getHigher(a[i]+k);
        pair<int,int> p1 = getMax(1,1,tot,1,l);
        pair<int,int> p2 = getMax(1,1,tot,r,tot);
        if (p1>p2)
            dp[i]=p1.first+1,b[i]=p1.second;
        else
            dp[i]=p2.first+1,b[i]=p2.second;
        if (dp[i]>ret)
            ret=dp[i],id=i;
        upd(1,1,tot,to[a[i]],make_pair(dp[i],i));
    }
    cout<<ret<<endl;
    PrintPath(id);
}

void pre()
{
    scanf("%d%I64d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        vec.push_back(a[i]);
    }
    sort(vec.begin(),vec.end());
    for (int i=0;i<vec.size();i++)
    {
        if (i==0)
            to[vec[i]]=++tot,from[tot]=vec[i];
        else if (vec[i]!=vec[i-1])
            to[vec[i]]=++tot,from[tot]=vec[i];
    }
    DP();
}
int main()
{
    pre();
}