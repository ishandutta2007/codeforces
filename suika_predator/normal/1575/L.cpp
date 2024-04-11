#include<bits/stdc++.h>
using namespace std;
pair<int,int> pr[233333];
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first==b.first)return a.second>b.second;
	else return a.first<b.first;
}
int f[233333],st[233333],top;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		pr[i]=make_pair(x,i-x);
//		cerr<<i<<' '<<pr[i].first<<' '<<(pr[i].second-x)/2<<endl;
	}
	sort(pr+1,pr+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(pr[i].second<0)continue;
//		cerr<<i<<' '<<pr[i].first<<' '<<pr[i].second<<endl;
		int l=0,r=top;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(pr[i].second>=pr[st[mid]].second)
				l=mid;
			else
				r=mid-1;
		}
		f[i]=l+1;
//		cerr<<"f "<<i<<' '<<l+1<<endl;
		if(f[i]>top or pr[i].second<pr[st[l+1]].second)st[l+1]=i;
		if(f[i]>top)top=f[i];
	}
	cout<<top<<endl;
	return 0;
}