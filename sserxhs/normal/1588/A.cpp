#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,x;
		cin>>n;
		multiset<int> s,b;
		for (int i=0;i<n;i++) cin>>x,s.insert(x);
		for (int i=0;i<n;i++) cin>>x,b.insert(x);
		int i=0;
		for (auto &x:s)
		{
			auto it=b.lower_bound(x);
			if (it==b.end()||*it>x+1) goto aa;
			b.erase(it);
		}
		cout<<"YES\n";continue;
		aa:cout<<"NO\n";
	}
}