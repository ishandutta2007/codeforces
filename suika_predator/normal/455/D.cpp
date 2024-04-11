#include<bits/stdc++.h>
using namespace std;
const int B=300;
int main()
{
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#endif
	int n;
	cin>>n;
	vector<int> a(n+5),L(n/B+5),R(n/B+5),bel(n+5);
	vector<deque<int>> blk(n/B+5);
	vector<vector<int>> cnt(n/B+5,vector<int>(n+5));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bel[i]=i/B;
		if(not L[i/B])L[i/B]=i;
		R[i/B]=i;
		blk[i/B].push_back(a[i]);
		cnt[i/B][a[i]]++;
	}
	int q,lastans=0;
	cin>>q;
	while(q--)
	{
		int ty,l,r,x;
		cin>>ty;
		//l=rng()%n+1,r=rng()%n+1,x=rng()%n+1;
		if(ty==1)
		{
			cin>>l>>r;
			l=(l+lastans-1)%n+1;
			r=(r+lastans-1)%n+1;
			if(l>r)swap(l,r);
			int lb=bel[l],rb=bel[r];
			int t=blk[rb][r-L[rb]];
			
			blk[rb].erase(blk[rb].begin()+(r-L[rb]));
			cnt[rb][t]--;
			blk[lb].insert(blk[lb].begin()+(l-L[lb]),t);
			cnt[lb][t]++;
			for(int i=lb;i<=rb-1;i++)
			{
				t=blk[i].back();
				blk[i].pop_back();
				cnt[i][t]--;
				blk[i+1].push_front(t);
				cnt[i+1][t]++;
			}
		}
		else
		{
			cin>>l>>r>>x;
			l=(l+lastans-1)%n+1;
			r=(r+lastans-1)%n+1;
			if(l>r)swap(l,r);
			x=(x+lastans-1)%n+1;
			int lb=bel[l],rb=bel[r];
			int ans=0;
			if(lb==rb)
			{
				for(int i=l-L[lb];i<=r-L[lb];i++)
					if(blk[lb][i]==x)
						ans++;
			}
			else
			{
				for(int i=l-L[lb];i<=R[lb]-L[lb];i++)
					if(blk[lb][i]==x)
						ans++;
				for(int i=0;i<=r-L[rb];i++)
					if(blk[rb][i]==x)
						ans++;
				for(int i=lb+1;i<=rb-1;i++)
					ans+=cnt[i][x];
			}
			cout<<ans<<"\n";
			lastans=ans;
		}
	}
	
	return 0;
}