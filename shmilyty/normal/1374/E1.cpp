#include<bits/stdc++.h>//1
using namespace std;
vector<int> a,b,c;
int n,k,ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int t,A,B;
		scanf("%d%d%d",&t,&A,&B);
		if(A&&B)
			c.push_back(t);
		if(A&&!B)
			a.push_back(t);
		if(!A&&B)
			b.push_back(t);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<min(a.size(),b.size());i++)
		c.push_back(a[i]+b[i]);
	sort(c.begin(),c.end());
	if(c.size()<k)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<k;i++)
		ans+=c[i];
	cout<<ans;
	return 0;
}