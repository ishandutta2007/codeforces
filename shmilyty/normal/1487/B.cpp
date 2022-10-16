#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n,k;
void solve()
{
	n=69;
	k=1337;
	int q=34,skp=35;
	int cnt=1;
	for(int i=1;i<=k;i++)
	{
		cout<<i<<" "<<cnt<<endl;
		cnt++;
		cnt=(cnt-1)%n+1;
		if(cnt==skp)
		{
			cnt++;
			skp=(skp+q)%n+1;
			cout<<"skp"<<skp<<endl;
		}
	}
}
signed main()
{
//	solve();
	t=read();
	while(t--)
	{
		int n=read();
		int k=read();
		if(n&1)
		{
			int q=n/2;
			int p1=(k-1)%(q*n);
			int p2=p1/q;
//			cout<<q<<" "<<p1<<" "<<p2<<endl;
			p1+=p2;
			cout<<(p1%n)+1<<endl;
		}
		else
			cout<<(k-1)%n+1<<endl;
	}
	return 0;
}