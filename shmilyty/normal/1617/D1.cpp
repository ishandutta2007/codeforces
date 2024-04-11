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
int t,n,lst,k,k1,a[30001];
int ask(int a,int b,int c)
{
	cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
	cout.flush();
	return read(); 
}
vector<int> v;
void solve()
{
	v.clear();
	memset(a,0,sizeof(a));
	n=read();
	lst=ask(0,1,2);
	for(int i=1;i<=n;i++)
	{
		int x=ask(i%n,(i+1)%n,(i+2)%n);
		if(lst!=x)
		{
			k=i-1;
			a[i]=lst;
			a[(i+2)%n+1]=x;
			break;
		}
	}
	k1=(k+3)%n;
//	cout<<k<<" "<<k1<<endl;
	for(int i=0;i<n;i++)
		if(i!=k1&&i!=k)
			a[i+1]=ask(i,k1,k);
	for(int i=1;i<=n;i++)
		if(!a[i])
			v.push_back(i);
	cout<<"! "<<v.size();
	for(int i:v)
		cout<<" "<<i;
	cout<<endl;
	cout.flush();
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}