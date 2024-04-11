#include<bits/stdc++.h>
using namespace std;
int n,b,q;
vector<pair<int,int>>v;
int main()
{
	scanf("%d%d%d",&n,&b,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	v.push_back({b,n});
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++)
		if(v[i].second>v[i+1].second)
			return puts("unfair");
	for(int k=0;k<32;k++)
	{
		int can=0;
		for(int i=0;i<=q;i++)
		{
			int pre=i?v[i-1].first+1:1;
			int quan=i?v[i].second-v[i-1].second:v[i].second;
			int s=0;
			for(int j=pre;j<=v[i].first;j++)
				if((k>>(j%5))&1)
					s++;
			can+=min(quan,s);
		}
		if(can<n/5*__builtin_popcount(k))
			return puts("unfair");
	}
	puts("fair");
    return 0;
}