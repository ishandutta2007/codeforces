#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll divi[MAXN];
vector<pair<P,int> > queries;
ll ans[MAXN];
ll bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,ll x)
{
    while(i<=200000)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void del(int x)
{
    divi[x]--;
    if(divi[x]) add(x,-divi[x]);
}
int main()
{
    for(int i=1;i<=200000;i++) 
        for(int j=2*i;j<=200000;j+=i)
            divi[j]++;
    for(int i=1;i<=200000;i++) add(i,1LL*divi[i]*(divi[i]-1)/2);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int len=(r-l+1);
        ans[i]=1LL*len*(len-1)*(len-2)/6;
        int lb=2*l;
        if(lb<=r) ans[i]-=((r/6)-(lb-1)/6);
        lb=(l+1)/2*5;
        if(lb<=r) ans[i]-=((r/15)-(lb-1)/15);
        queries.push_back(make_pair(P(l,r),i));
    }
    sort(queries.begin(),queries.end());
    int now=1;
    for(int i=0;i<(int)queries.size();i++)
    {
        int l=queries[i].F.F,r=queries[i].F.S,id=queries[i].S;
        while(now<l)
        {
            for(int i=2*now;i<=200000;i+=now) del(i);
            now++;
        }
        ans[id]-=(sum(r)-sum(l+1));
    }
    for(int i=0;i<t;i++) printf("%lld\n",ans[i]);
    return 0;
}