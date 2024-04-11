#include<bits/stdc++.h>
#define int long long
using namespace std;
int vis[123456];
main()
{
	int n,m,s,t;
	scanf("%lld %lld %lld %lld",&n,&m,&s,&t);
	m--;
	s--;
	int x = t%n;
	for(int i = x;i>0;i--)
	{
		if(s<=m) s+=i;
		else s-=i;
		s = s%n + n;
		s %= n;
	}		
	int cur = 0;
	int ans = 0;
	int pos = s;
	int ppp;
	while(true)
	{
		if(vis[s]!=0) 
		{
			ans = cur - vis[s];
			ppp = vis[s];
			break;
		}
		vis[s] = cur++;
		for(int i = n;i>0;i--)
		{
			if(s<=m) s+=i;
			else s-=i;
			s = s%n + n;
			s %= n;
		}				
	}
	t /= n;
	if(!t){}
	else if(t<=ppp) 
	{
		for(int i = 0;i<n;i++)
		{
			if(vis[i]==t) pos = i; 
		}
	}
	else 
	{
		t-= ppp;
		t%= ans;
		for(int i = 0;i<n;i++)
		{
			if(vis[i]==t+ppp) pos = i; 
		}		
	}
	printf("%lld\n",pos+1);
	
	return 0;
}