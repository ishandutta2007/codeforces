#include<bits/stdc++.h>
using namespace std;
int cnt[555555];
int count(int l,int r)
{
	return cnt[r]-cnt[l-1];
}
int f[555555][19];
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,q,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=m;i++)
		cnt[i]+=cnt[i-1];
	for(int d=1;d<=18;d++)
	{
		for(int i=1;i<=m;i++)
		{
			f[i][d]=f[i][d-1]^f[i+(1<<(d-1))][d-1];
			if(count(i+(1<<(d-1)),i+(1<<d)-1)%2==1)
				f[i][d]^=1<<(d-1);
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		int ans=0;
		for(int i=18;i>=0;i--)
		{
			if(x+(1<<i)<=y)
			{
//				cerr<<"go "<<i<<' '<<f[x][i]<<endl;
				ans^=f[x][i];
				x+=(1<<i);
				if(count(x,y)%2==1)
					ans^=(1<<i);
			}
		}
		cout<<(ans==0?'B':'A');
//		cerr<<ans<<endl;
	}
	
	return 0;
}