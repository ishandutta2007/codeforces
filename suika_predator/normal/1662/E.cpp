#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int> a(n+5),pos(n+5),BIT(n+5);
		auto add=[&](int pos,int del)
		{
			for(int x=pos;x<=n;x+=x&-x)
			{
				BIT[x]+=del;
			}
		};
		auto query=[&](int pos)
		{
			int ret=0;
			for(int x=pos;x;x-=x&-x)
			{
				ret+=BIT[x];
			}
			return ret;
		};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			pos[a[i]]=i;
			add(i,1);
		}
		long long ans=-1ll*n*(n-1)/2;
		for(int i=n;i>1;i--)
		{
			add(pos[i],-1);
			int L=pos[i-1],R=pos[i];
			int len=0;
			if(L<R)len+=query(R)-query(L-1);
			else len+=query(R)+query(n)-query(L-1);
			ans+=1ll*len*(n-i+1);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}