#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	vector<int> a(n+5);
	vector<vector<int>> pos(q+5);
	a[0]=1;
	set<int> s;
	int ok=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==q)ok=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(not ok)
			{
				ok=1;
				a[i]=q;
			}
			else a[i]=a[i-1];
		}
		pos[a[i]].push_back(i);
		s.insert(i);
	}
	s.insert(n+1);
	if(not ok)
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=q;i>=1;i--)
	{
		if(pos[i].empty())
		{
			continue;
		}
		int minp=*min_element(pos[i].begin(),pos[i].end()),maxp=*max_element(pos[i].begin(),pos[i].end());
		auto it=s.find(minp);
//		cerr<<i<<' '<<minp<<' '<<maxp<<endl;
		assert(it!=s.end());
		int cur=*it;
		do
		{
			cur=*it;
			if(a[cur]!=i)
			{
				cout<<"NO\n";
				return 0;
			}
			it=s.erase(it);
			assert(it!=s.end());
		}
		while(cur!=maxp);
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}