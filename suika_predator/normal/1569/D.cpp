#include<bits/stdc++.h>
using namespace std;
map<int,int> posx,posy;
map<pair<int,int>,long long> cntxy,cntyx;
map<int,long long> cntx,cnty;
int x[233333],y[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,m,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			posx[x[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>y[i];
			posy[y[i]]=i;
		}
		int xx,yy;
		for(int i=1;i<=k;i++)
		{
			cin>>xx>>yy;
			if(posx.find(xx)!=posx.end() and posy.find(yy)!=posy.end())continue;
			if(posx.find(xx)!=posx.end())
			{
				int x0=posx[xx];
				int y0=posy.lower_bound(yy)->second;
				cntxy[make_pair(x0,y0)]++;
				cntx[y0]++;
			}
			else
			{
				int y0=posy[yy];
				int x0=posx.lower_bound(xx)->second;
				cntyx[make_pair(y0,x0)]++;
				cnty[x0]++;
			}
		}
		long long ans=0;
		for(auto z:cntx)
		{
//			cerr<<"x "<<z.first<<' '<<z.second<<endl;
			ans+=z.second*(z.second-1)/2;
		}
		for(auto z:cnty)
		{
//			cerr<<"y "<<z.first<<' '<<z.second<<endl;
			ans+=z.second*(z.second-1)/2;
		}
		for(auto z:cntxy)
		{
//			cerr<<"xy "<<z.first.first<<' '<<z.first.second<<' '<<z.second<<endl;
			ans-=z.second*(z.second-1)/2;
		}
		for(auto z:cntyx)
		{
//			cerr<<"yx "<<z.first.first<<' '<<z.first.second<<' '<<z.second<<endl;
			ans-=z.second*(z.second-1)/2;
		}
		cout<<ans<<endl;
		posx.clear();posy.clear();
		cntx.clear();cnty.clear();
		cntxy.clear();cntyx.clear();
	}
	
	
	return 0;
}