#include<bits/stdc++.h>
using namespace std;
int ans[2333][2333];
int query(int x,int y)
{
	if(x>y)swap(x,y);
	if(ans[x][y])return ans[x][y];
	cout<<"? "<<x<<' '<<y<<endl;
	int t;
	cin>>t;
	return ans[x][y]=t;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int x=-1,y=-1,o;
	for(int i=1;i<=n;i++)
	{
//		cerr<<"round "<<i<<' '<<x<<' '<<y<<endl;
		if(x==-1)
		{
			x=i;
			continue;
		}
		if(y==-1)
		{
			y=i;
			o=query(x,y);
			continue;
		}
		int t=query(x,i);
		if(t<o)y=i,o=t;
		else if(t==o)
		{
			//throw x
			int z=query(y,i);
			if(z>=o)
			{
				x=y=-1;
			}
			else //z<o
			{
				x=i,o=z;
			}
		}
	}
	assert(x!=-1);
	mt19937 rng((unsigned long long)(new char));
	int zero=-1;
	if(y!=-1)
	{
		while(zero==-1)
		{
			int i=rng()%n+1;
			if(i==x or i==y)continue;
			int t=query(x,i),z=query(y,i);
			if(t<z)zero=x;
			else if(t>z)zero=y;
		}
	}
	else zero=x;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++)
	{
		if(i==zero)a[i]=0;
		else
		{
			a[i]=query(zero,i);
		}
	}
	cout<<"!";
	for(int i=1;i<=n;i++)
	{
		cout<<' '<<a[i];
	}
	cout<<endl;
	return 0;
}