#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,k,a[MAXN];
P stmin[MAXN][20],stmax[MAXN][20];
int pre[MAXN];
void init(int n,P *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;--i)
    {
        stmin[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<j-1)][j-1]);
    }
    for(int i=n;i>=1;--i)
    {
        stmax[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<j-1)][j-1]);
    }
}
P query_min(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
}
P query_max(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
}
vector<pair<int,P> >ones;
vector<P> queries;
P covert[MAXN];
int coverone[MAXN],cnt[MAXN],sum[MAXN];
vector<int> added[MAXN],removed[MAXN];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++) 
	{
		int type,l,r,x;
		scanf("%d",&type);
		if(type==0)
		{
			scanf("%d%d%d",&l,&r,&x);
			if(x==0) 
			{
				added[l].push_back(i);
				removed[r+1].push_back(i);
			}
			else ones.push_back(make_pair(i,P(l,r)));
		}
		else
		{
			scanf("%d",&x);
			queries.push_back(P(i,x));
		}
	}
	for(int i=1;i<=n;i++) coverone[i]=INF;
	for(int i=1;i<=n;i++) covert[i].S=i;
	set<int> s;
	for(int i=1;i<=n;i++)
	{
		for(auto x:added[i]) s.insert(x);
		for(auto x:removed[i]) s.erase(x);
		if(s.size())
		{
			covert[i].F=*s.begin();
			cnt[i]++;
		}
	}
	init(n,covert);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
	for(auto p:ones)
	{
		int t=p.F,l=p.S.F,r=p.S.S;
		if(sum[r]-sum[l-1]==r-l)
		{
			P qq=query_max(l,r);
			P pp=query_min(l,r);
			coverone[pp.S]=min(coverone[pp.S],max(t,qq.F));
			assert(!covert[pp.S].F);
		}
	}
	for(auto p:queries)
	{
		if(covert[p.S].F&&covert[p.S].F<=p.F) puts("NO");
		else if(coverone[p.S]!=INF&&coverone[p.S]<=p.F) puts("YES");
		else puts("N/A");
	}
	return 0;
}