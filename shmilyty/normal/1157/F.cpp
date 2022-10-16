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
int n,ans,cnt,a[200002],num[200002];
signed main()
{
//	freopen("data.txt","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
		num[read()]++;
	for(int i=1;i<=2e5;i++)
		if(num[i])
		{
			int l=i+1,sum=num[i];
			while(l<=2e5&&num[l]>1)
				sum+=num[l++];
			if(l<=2e5&&num[l]==1)
				sum++;
			else
				l--;
//			cout<<sum<<endl;
//			system("pause");
			if(sum>ans)
			{
				ans=sum;
				cnt=i;
			}
			i=max(i,l-1);
		}
	cout<<ans<<endl;
	int end=cnt,sum=0;
	while(num[end]&&sum+num[end]<=ans)
		sum+=num[end++];
	end--;
//	cout<<cnt<<" "<<end<<endl;
//	system("pause");
	for(int i=cnt;i<=end;i++)
	{
		num[i]--;
		while(num[i]--)
			cout<<i<<" ";
	}
	for(int i=end;i>=cnt;i--)
		cout<<i<<" ";
	return 0;
}