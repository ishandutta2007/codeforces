#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,m;
int s[5555],f[5555],h[5555],l[5555],r[5555],lp[5555],rp[5555];
int tot[5555];
int id[5555][5555];
long long cnt[5555],maxx;
int lvis[5555],rvis[5555],vis[5555];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=m;i++)
	{
		cin>>f[i]>>h[i];
		id[f[i]][h[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		tot[s[i]]++;
//		lp[id[s[i]][tot[s[i]]]]=i;
		l[i]=id[s[i]][tot[s[i]]];
	}
	memset(tot,0,sizeof(tot));
	for(int i=n;i>=1;i--)
	{
		tot[s[i]]++;
//		rp[id[s[i]][tot[s[i]]]]=i;
		r[i]=id[s[i]][tot[s[i]]];
	}
//	for(int i=1;i<=n;i++)cerr<<i<<' '<<l[i]<<' '<<r[i]<<endl;
	for(int mid=0;mid<=n;mid++)
	{
		if(mid&&l[mid]==0)continue;
		//l[mid] is special
		memset(lvis,0,sizeof(lvis));
		memset(rvis,0,sizeof(rvis));
		memset(vis,0,sizeof(vis));
//		cerr<<mid<<' '<<l[mid]<<' '<<f[l[mid]]<<endl;
		lvis[f[l[mid]]]++;
		vis[l[mid]]++;
		for(int i=1;i<=mid;i++)
		{
			if(f[l[i]]!=f[l[mid]])
			{
//				cerr<<"addl "<<l[i]<<' '<<f[l[i]]<<endl;
				lvis[f[l[i]]]++;
				vis[l[i]]++;
			}
		}
		for(int i=n;i>mid;i--)
		{
			if(r[i]!=l[mid])
			{
//				cerr<<"addr "<<r[i]<<' '<<f[r[i]]<<endl;
				rvis[f[r[i]]]++;
				vis[r[i]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
//			cerr<<mid<<' '<<i<<' '<<lvis[i]<<' '<<rvis[i]<<endl;
			if(lvis[i]==0)lvis[i]=rvis[i],rvis[i]=0;
			else if(rvis[i])lvis[i]*=rvis[i];
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i]==2)
			{
				if(lvis[f[i]]==1)lvis[f[i]]++,rvis[f[i]]=0;
				else lvis[f[i]]--;
			}
		}
		long long tcnt=1,tans=0;
		for(int i=1;i<=n;i++)
		{
//			cerr<<i<<' '<<lvis[i]<<' '<<rvis[i]<<endl;
			if(lvis[i])
			{
				tcnt=tcnt*lvis[i]%MOD;
				tans++;
			}
			if(rvis[i])tans++;
		}
//		cerr<<tcnt<<' '<<tans<<endl;
		cnt[tans]+=tcnt;
		maxx=max(maxx,tans);
	}
	cout<<maxx<<' '<<cnt[maxx]%MOD<<endl;
	return 0;
}