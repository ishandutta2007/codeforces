#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int a,b,c;
	edge(int x,int y,int z){a=x,b=y,c=min(z,1000000);}
};
vector<edge> eg,ans;
int l,r;
int n=32,m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>l>>r;
	cout<<"YES"<<endl;
	if(l==r)
	{
		cout<<2<<' '<<1<<endl;
		cout<<1<<' '<<2<<' '<<l<<endl;
		return 0;
	}
	for(int i=0;i<=25;i++)
	{
		for(int j=i+1;j<=25;j++)
		{
			eg.push_back({i,j,1<<(max(0,i-1))});
		}
	}
	if(l==1)
	{
		for(auto x:eg)
		{
			ans.push_back({x.a+1,x.b+1,x.c});
		}
		int s=1;
		ans.push_back({1,n,1});
		r--;
		for(int c=1;c<=25;c++)
		{
			if(r&(1<<(c-1)))
				ans.push_back({c+1,n,s}),s+=(1<<(c-1));
		}
	}
	else
	{
		for(auto x:eg)
		{
			ans.push_back({x.a+2,x.b+2,x.c});
		}
		int s=1;
		ans.push_back({1,2,l-1});
		ans.push_back({1,n,l});
		r-=l;
		for(int c=1;c<=25;c++)
		{
			if(r&(1<<(c-1)))
				ans.push_back({c+2,n,s}),s+=(1<<(c-1));
		}
	}
	cout<<n<<' '<<ans.size()<<endl;
	for(auto x:ans)cout<<x.a<<' '<<x.b<<' '<<x.c<<endl;
	return 0;
}