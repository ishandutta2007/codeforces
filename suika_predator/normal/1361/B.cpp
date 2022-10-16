#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int T,n,m,k,x;
map<int,int> cnt;
inline int poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		cnt.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			cnt[x]++;
		}
		if(k==1)
		{
			cout<<n%2<<endl;
			continue;
		}
		long long ans=0;
		int cur=(--cnt.end())->first;
		for(;;)
		{
//			cerr<<cur<<' '<<cnt[cur]<<endl;
			if(cnt[cur]%2!=0)
			{
				cnt.erase(cur);
				long long diff=k;
				int i;
				for(i=cur-1;i>=0&&diff<=1000000000;i--,diff*=k)
				{
					if(cnt[i]>=diff)
					{
						cnt[i]-=diff;
						diff=0;
						break;
					}
					else
					{
						diff-=cnt[i];
						cnt.erase(i);
					}
				}
				if(diff!=0)
				{
					i++;diff/=k;
					ans+=diff%MOD*poww(k,i)%MOD;
//					cerr<<i<<' '<<diff<<' '<<ans<<endl;
					for(auto _:cnt)
					{
//						cerr<<"run "<<_.first<<' '<<_.second<<endl;
						ans-=1ll*_.second*poww(k,_.first)%MOD;
					}
					ans%=MOD;
					ans+=MOD;
					ans%=MOD;
					break;
				}
			}
			else cnt.erase(cur);
			if(cnt.empty())break;
			auto _=--(cnt.lower_bound(cur));
			cur=_->first;
		}
		cout<<ans<<endl;
	}
	return 0;
}