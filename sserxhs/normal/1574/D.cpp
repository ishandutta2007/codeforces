#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[10];
set<vector<int>> s,t;
struct cmp
{
	bool operator()(vector<int> &x,vector<int> &y)
	{
		int ans=0;
		for (int i=0;i<n;i++) ans+=a[i][x[i]]-a[i][y[i]];
		return ans<0;
	}
};
priority_queue<vector<int>,vector<vector<int>>,cmp> q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int> tmp(n);
	for (int i=0;i<n;i++) 
	{
		cin>>m;
		a[i].resize(m);tmp[i]=m-1;
		for (auto &x:a[i]) cin>>x;
	}
	q.push(tmp);
	cin>>m;
	while (m--)
	{
		for (auto &x:tmp) cin>>x,--x;
		s.insert(tmp);
	}
	while (q.size())
	{
		tmp=q.top();q.pop();
		if (s.find(tmp)==s.end())
		{
			for (auto x:tmp) cout<<x+1<<' ';
			return 0;
		}
		for (auto &x:tmp) if (x)
		{
			--x;
			if (t.find(tmp)==t.end()) q.push(tmp),t.insert(tmp);
			++x;
		}
	}
	assert(0);
}