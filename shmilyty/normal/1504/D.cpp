#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,cx,cy;
pair<int,int> x[5001],y[5001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			if((i+l)&1)
				x[++cx]=make_pair(i,l);
			else
				y[++cy]=make_pair(i,l);
	int nx=1,ny=1;
	for(int i=1;i<=n*n;i++)
	{
		int a=read();
		switch(a)
		{
			case 1:{
				if(ny<=cy)
				{
					cout<<"2 "<<y[ny].first<<" "<<y[ny].second<<endl;
					ny++;
				}
				else
				{
					cout<<"3 "<<x[nx].first<<" "<<x[nx].second<<endl;
					nx++;
				}
				break;
			}
			case 2:{
				if(nx<=cx)
				{
					cout<<"1 "<<x[nx].first<<" "<<x[nx].second<<endl;
					nx++;
				}
				else
				{
					cout<<"3 "<<y[ny].first<<" "<<y[ny].second<<endl;
					ny++;
				}
				break;
			}
			case 3:{
				if(nx<=cx)
				{
					cout<<"1 "<<x[nx].first<<" "<<x[nx].second<<endl;
					nx++;
				}
				else
				{
					cout<<"2 "<<y[ny].first<<" "<<y[ny].second<<endl;
					ny++;
				}
				break;
			}
		}
		fflush(stdout);
	}
}
signed main()
{
	solve();
	return 0;
}