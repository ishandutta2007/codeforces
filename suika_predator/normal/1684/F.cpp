#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		vector<int> a(n+5);
		vector<pair<int,int>> tmp;
		map<int,vector<int>> mp;
		vector<int> L(n+5),R(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			mp[a[i]].push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			int l,r;
			cin>>l>>r;
			tmp.emplace_back(l,r);
		}
		sort(tmp.begin(),tmp.end());
		vector<pair<int,int>> v;
		int maxr=0,cur=0;
		for(int i=1;i<=n;i++)
		{
			while(cur<tmp.size() and tmp[cur].first<=i)
			{
				maxr=max(maxr,tmp[cur].second);
				cur++;
			}
			maxr=max(maxr,i);
			R[i]=maxr;
		}
		for(auto &z:tmp)swap(z.first,z.second);
		sort(tmp.begin(),tmp.end(),greater<pair<int,int>>());
		int minl=n;
		cur=0;
		for(int i=n;i>=1;i--)
		{
			while(cur<tmp.size() and tmp[cur].first>=i)
			{
				minl=min(minl,tmp[cur].second);
				cur++;
			}
			minl=min(minl,i);
			L[i]=minl;
		}
//		for(int i=1;i<=n;i++)cerr<<i<<' '<<L[i]<<' '<<R[i]<<endl;
		tmp.clear();
		int minr=0,maxl=n;
		for(int i=1;i<=n;i++)
		{
			vector<int> &vec=mp[a[i]];
			int ls=*(lower_bound(vec.begin(),vec.end(),L[i]));
			if(ls!=i)
			{
				tmp.emplace_back(ls,i);
				minr=max(minr,ls);
				maxl=min(maxl,i);
			}
			int rs=*--(upper_bound(vec.begin(),vec.end(),R[i]));
			if(rs!=i)
			{
				tmp.emplace_back(i,rs);
				minr=max(minr,i);
				maxl=min(maxl,rs);
			}
		}
		sort(tmp.begin(),tmp.end());
//		cerr<<"----------"<<endl;
//		for(auto z:tmp)cerr<<z.first<<' '<<z.second<<endl;
//		cerr<<"----------"<<endl;
		int ans=minr;
		cur=0;
		for(int i=1;i<=maxl;i++)
		{
			while(cur<tmp.size() and tmp[cur].first<i)
			{
				minr=max(minr,tmp[cur].second);
				cur++;
			}
//			cerr<<"get "<<i<<' '<<minr<<endl;
			minr=max(minr,i);
			ans=min(ans,minr-i+1);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}