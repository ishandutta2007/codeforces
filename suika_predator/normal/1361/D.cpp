#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
map<pair<int,int>,vector<double> > mp;
double add[1111111];
int top;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x==0&&y==0)continue;
		double dis=sqrt(1.0*x*x+1.0*y*y);
		int d=__gcd(abs(x),abs(y));x/=d,y/=d;
		mp[make_pair(x,y)].push_back(dis);
	}
	for(auto _:mp)
	{
		auto &vec=_.second;
		sort(vec.begin(),vec.end());
		if(vec.size()<=k/2)
		{
			for(int i=1;i<=vec.size();i++)
			{
				add[++top]=(k-2*i+1)*vec[vec.size()-i];
			}
		}
		else
		{
			for(int i=1;i<=k/2;i++)
			{
				add[++top]=(k-2*i+1)*vec[vec.size()-i];
			}
			double sub=0;
			for(int i=0;i<min((int)vec.size()-k/2,k/2+1);i++)
			{
				add[++top]=(k-k/2-k/2-1)*vec[i]-2*sub;
				sub+=vec[i];
			}
		}
	}
//	for(int i=1;i<=top;i++)cerr<<i<<' '<<add[i]<<endl;
	sort(add+1,add+top+1);
	reverse(add+1,add+top+1);
	double ans=0;
	for(int i=1;i<k;i++)ans+=add[i];
	if(add[k]>0)ans+=add[k];
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}