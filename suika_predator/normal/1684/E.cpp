#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		vector<int> a(n+5);
		map<int,int> cnt;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		k=min(n,k);
		int cur=0,mex=0;
		for(int i=0;i<=n+k+1;i++)
		{
			if(not cnt.contains(i))
			{
				cur++;
				if(cur==k+1)
				{
					mex=i;
					break;
				}
			}
		}
		vector<pair<int,int>> srt;
		for(auto [x,y]:cnt)
		{
			if(x>mex)
			{
//				cerr<<x<<" cnt="<<y<<endl;
				srt.push_back(make_pair(0,y));
			}
		}
		int ans=0;
		sort(srt.begin(),srt.end());
		for(auto [x,y]:srt)
		{
			if(k>=y)k-=y;
			else ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}