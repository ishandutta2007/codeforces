#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
ll id[MAXN];
map<ll,ll> mp;
vector<ll> G[MAXN];
set<ll> s;
vector<P> ans;
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		s.insert(a[i]);
	}
	vector<ll> v(s.begin(),s.end());
	ll tt=0;
	for(ll i=0;i<v.size();i++)
	{
		tt++;
		mp[v[i]]=tt;
		id[tt]=v[i];
	}
	s.clear();
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	for(ll i=0;i<n;i++)
	{
		G[mp[a[i]]].push_back(i);
		if(G[mp[a[i]]].size()==2) pq.push(a[i]);
	}
	while(pq.size())
	{
		ll p=pq.top();
		pq.pop();
		ll res=p*2;
		if(mp.find(res)==mp.end()) {tt++; mp[res]=tt; id[tt]=res;}
		ll save=-1;
		sort(G[mp[p]].begin(),G[mp[p]].end());
		for(ll i=0;i<G[mp[p]].size();i+=2)
		{
			if(i==G[mp[p]].size()-1) {save=G[mp[p]][i]; break;}
			G[mp[res]].push_back(G[mp[p]][i+1]);
			if(G[mp[res]].size()==2) pq.push(res);
		}
		G[mp[p]].clear();
		if(save!=-1) G[mp[p]].push_back(save);
	}
	for(ll i=1;i<=tt;i++)
		if(G[i].size()>0) ans.push_back(P(G[i][0],id[i]));
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(ll i=0;i<ans.size();i++)
		printf("%I64d ",ans[i].S);
	return 0;
}