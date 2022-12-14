#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
map<int,int> mp;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n==1)
	{
		if(m==0)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<-1;
			return 0;
		}
	}
	int k=m-n/2+1,n1;
	if(k<=0)
	{
		cout<<-1;
		return 0;
	}
	cout<<k<<' '<<2*k<<' ';
	mp[k]=mp[2*k]=1;
	int t=1;
	for(n1=2;n1*2<=n;n1++)
	{
		while(mp[t]||mp[t+1])
			t++;
		printf("%d %d ",t,t+1);
		t=t+2;
		
	}
	while(mp[t])
		t++;
	if(n%2)
		printf("%d",t);
}