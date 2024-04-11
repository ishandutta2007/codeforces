#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
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
int n,k,t1,t2,cnt,lst=-INF;
map<int,int> mp1,mp2;
array<int,2> ans[2000001],v[2000001];
multiset<pair<int,int>> s;
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		mp1[read()]++;
		mp2[read()+1]--;
	}
	for(auto i:mp1)
		v[++t1]={i.first,i.second};
	for(auto i:mp2)
		v[++t1]={i.first,i.second};
	sort(v+1,v+1+t1);
	for(int i=1;i<=t1;i++)
	{
		cnt+=v[i][1];
		if(cnt>=k&&lst==-INF)
			lst=v[i][0];
		if(cnt<k&&lst!=-INF)
		{
			v[++t2]={lst,v[i][0]};
			lst=-INF;
		}
	}
	printf("%lld\n",t2);
//	cout<<t2<<endl;
	for(int i=1;i<=t2;i++)
		printf("%lld %lld\n",v[i][0],v[i][1]-1);
//		cout<<v[i][0]<<" "<<v[i][1]-1<<endl;
	return 0;
}