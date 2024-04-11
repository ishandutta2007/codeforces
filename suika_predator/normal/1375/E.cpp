#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[2333],pos[2333];
pair<int,int> srt[2333];
vector<pair<int,int> > ans;
inline void mov(int u,int v)
{
//	cerr<<"mov "<<u<<' '<<v<<endl;
	ans.push_back(make_pair(u,v));
	swap(pos[a[u]],pos[a[v]]);
	swap(a[u],a[v]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		srt[i]=make_pair(a[i],i);
	}
	sort(srt+1,srt+n+1);
	for(int i=1;i<=n;i++)
	{
		a[srt[i].second]=i;
		pos[i]=srt[i].second;
	}
/*	for(int i=1;i<=n;i++)
	{
		cerr<<i<<' '<<pos[i]<<endl;
	}
*/	for(int i=n;i>=1;i--)
	{
		for(int j=a[i];j<i;j++)
		{
			mov(pos[j+1],i);
//			for(int t=1;t<=n;t++)cerr<<a[t]<<' ';cerr<<endl;
		}
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x.first<<' '<<x.second<<endl;
	return 0;
}