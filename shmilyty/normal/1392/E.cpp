#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
vector<pair<int,int> > ans;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i&1)
				printf("%lld ",(1ll<<(i+j-2)));
			else 
				printf("0 ");
		}
		printf("\n");
	}
	cout<<flush;
	scanf("%lld",&q);
	while(q--)
	{
		int x;
		scanf("%lld",&x);
		ans.clear();
		ans.push_back(make_pair(1,1));
		for(int i=1;i<=2*n-2;i++)
		{
			if((1ll<<i)&x) 
			{
				if(ans.back().first&1) 
					ans.push_back(make_pair(ans.back().first,ans.back().second+1));
				else 
					ans.push_back(make_pair(ans.back().first+1,ans.back().second));
			}
			else 
			{
				if(!(ans.back().first&1)) 
					ans.push_back(make_pair(ans.back().first,ans.back().second+1));
				else 
					ans.push_back(make_pair(ans.back().first+1,ans.back().second));
			}
		}
		for(auto u:ans) 
			printf("%lld %lld\n",u.first,u.second);
		cout<<flush;
	}
	return 0;
}