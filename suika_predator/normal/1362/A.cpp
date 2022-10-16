#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
long long x,y;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		int cnt=0;
		long long tx=x,ty=y;
		while(tx%2==0)tx/=2;
		while(ty%2==0)ty/=2;
		if(tx!=ty)
		{
			cout<<-1<<endl;
		}
		else
		{
			long long t=0;
			if(x>y)t=x/y;
			else t=y/x;
			while(t>1)t/=2,cnt++;
			cout<<(cnt+2)/3<<endl;
		}
	}
	return 0;
}