#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,w[14],ans[1001],num[1001];
vector<int> ask[14];
int query(vector<int> v)
{
	if(v.size()==0)
		return 0;
	cout<<"? "<<v.size();
	for(auto i:v)
		cout<<" "<<i;
	cout<<endl;
	int res;
	scanf("%lld",&res);
	return res;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<(1<<13);i++)
		if(__builtin_popcount(i)==6)
		{
			num[++cnt]=i;
			for(int j=0;j<13;j++)
				if(!(i&(1<<j)))
					ask[j].push_back(cnt);
			if(cnt==n)
				break;
		}
	for(int i=0;i<13;i++)
		w[i]=query(ask[i]);
	cout<<"!";
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=0;j<13;j++)
			if(num[i]&(1<<j)) 
				ans|=w[j];
		cout<<" "<<ans;
	}
	return 0;
}