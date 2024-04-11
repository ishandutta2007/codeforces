#include<bits/stdc++.h>
using namespace std;
int a[233333],ans[233333];
vector<pair<int,int> > vec;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vector<pair<int,int> > tmp;
		tmp.emplace_back(i,a[i]);
		int ok=1;
		if(a[i]==1)ok=0;
		int pre=i;
		for(auto &[x,y]:vec)
		{
			int g=gcd(y,a[i]);
			//x~pre-1 gcd=g
			if(i-(pre-1)+1<=g and g<=i-x+1)ok=0;
			if(tmp.back().second==g)tmp.pop_back();
			tmp.emplace_back(x,g);
			pre=x;
		}
		if(not ok)
		{
			ans[i]=ans[i-1]+1;
			vec.clear();
			pre=i;
		}
		else
		{
			ans[i]=ans[i-1];
			vec.swap(tmp);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" \n"[i==n];
	}
	return 0;
}