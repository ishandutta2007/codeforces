#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<tuple<int,int,int,int>> a(n);
		for(int i=0;i<n;i++)
		{
			int c,l,r;
			cin>>c>>l>>r;
			a[i]={r,l,c,i+1};
		}
		sort(a.begin(),a.end());
		vector<int> pa(n+5);
		function<int(int)> find=[&](int x){return pa[x]?pa[x]=find(pa[x]):x;};
		int cnt=n;
		function<void(int,int)> merge=[&](int x,int y)
		{
			int px=find(x),py=find(y);
			if(px!=py)
			{
				cnt--;
				pa[py]=px;
			}
		};
		stack<pair<int,int>> st0,st1;
		for(auto [r,l,c,id]:a)
		{
			if(c==0)
			{
				int maxx=-1,ii=0;
				while(not st1.empty() and st1.top().first>=l)
				{
					auto [R,id2]=st1.top();st1.pop();
					ii=id2;
					merge(id2,id);
					maxx=max(maxx,R);
				}
				if(maxx!=-1)
				{
					st1.emplace(maxx,ii);
				}
				st0.emplace(r,id);
			}
			else //c==1
			{
				int maxx=-1,ii=0;
				while(not st0.empty() and st0.top().first>=l)
				{
					auto [R,id2]=st0.top();st0.pop();
					ii=id2;
					merge(id2,id);
					maxx=max(maxx,R);
				}
				if(maxx!=-1)
				{
					st0.emplace(maxx,ii);
				}
				st1.emplace(r,id);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}