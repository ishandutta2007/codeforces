#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
string s;
set<pair<pair<int,int>,pair<int,int> > > ss;
inline int get(int a,int b,int c,int d)
{
	if(a>c)swap(a,c);
	if(b>d)swap(b,d);
	auto t=make_pair(make_pair(a,b),make_pair(c,d));
	if(ss.find(t)!=ss.end())return 1;
	else ss.insert(t);
	return 5;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		int ans=0;
		ss.clear();
		cin>>s;
		int ox=0,oy=0,nx=0,ny=0;
		for(auto x:s)
		{
			if(x=='N')nx=ox,ny=oy+1;
			else if(x=='S')nx=ox,ny=oy-1;
			else if(x=='W')nx=ox-1,ny=oy;
			else nx=ox+1,ny=oy;
			ans+=get(ox,oy,nx,ny);
			ox=nx,oy=ny;
		}
		cout<<ans<<endl;
	}
	return 0;
}