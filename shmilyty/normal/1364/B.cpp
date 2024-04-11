#include<bits/stdc++.h>
using namespace std;
int t,n,ans,p[100001];
vector<int> a;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a.clear();
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		a.push_back(p[1]);
		for(int i=2;i<n;i++)
			if((p[i-1]>p[i]&&p[i+1]>p[i])||(p[i-1]<p[i]&&p[i+1]<p[i]))
				a.push_back(p[i]);
		a.push_back(p[n]);
		for(int i=1;i<a.size();i++)
			ans+=abs(a[i]-a[i-1]);
		cout<<a.size()<<endl;
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}