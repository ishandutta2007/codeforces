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
int t,n,top,stk[200001],a[200001],num[200001];
void solve()
{
	n=read();
	for(int i=0;i<=n;i++)
		num[i]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		num[a[i]]++;
	}
	int cnt=0,tot=0,lst=0;
	for(int i=0;i<=n;i++)
	{
//		cout<<i<<" "<<num[i]<<" "<<tot<<endl;
		cnt+=num[i];
		if(i&&!num[i-1])
		{
			if(!top)
			{
				for(int l=i;l<=n;l++)
					cout<<"-1 ";
				cout<<endl;
				return ;
			}
			tot+=i-1-stk[top];
			top--;
		}
//		cout<<tot<<endl;
		cout<<tot+num[i]<<" ";
		if(num[i])
			for(int l=1;l<num[i];l++)
				stk[++top]=i;
	}
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}