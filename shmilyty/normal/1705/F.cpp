#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,k,A,B,ok[1001],ok1[1001],ans[1001];
int query(int *q)
{
	for(int i=1;i<=n;i++)
		cout<<(q[i]?'T':'F');
	cout<<endl;
	int x=read();
	if(x==n)
		exit(0);
	return x;
}
signed main()
{
	n=read();
	k=n/3;
	A=query(ok);
	if(n%3)
	{
		ok[k*3+1]=1;
		if(query(ok)>A)
			ans[k*3+1]=1;
		ok[k*3+1]=0;
	}
	if(n%3>1)
	{
		ok[k*3+2]=1;
		if(query(ok)>A)
			ans[k*3+2]=1;
		ok[k*3+2]=0;
	}
	for(int i=0;i<k;i++)
		ok1[i*3+1]=1;
	B=query(ok1);
	for(int i=0;i<k;i++)
	{
		ok[i*3+1]=ok[i*3+2]=1;
		int C=query(ok);
		ok[i*3+1]=ok[i*3+2]=0;
		if(C>A)
		{
			ans[i*3+1]=ans[i*3+2]=1;
			ok[i*3+3]=1;
			if(query(ok)>A)
				ans[i*3+3]=1;
			ok[i*3+3]=0;
		}
		if(C<A)
		{
			ok[i*3+3]=1;
			if(query(ok)>A)
				ans[i*3+3]=1;
			ok[i*3+3]=0;
		}
		if(A==C)
		{
			for(int l=1;l<=3;l++)
				ok1[i*3+l]^=1;
			C=query(ok1);
			for(int l=1;l<=3;l++)
				ok1[i*3+l]^=1;
			if(B-C==3)
				ans[i*3+1]=1;
			if(B-C==-1)
				ans[i*3+2]=1;
			if(B-C==1)
				ans[i*3+1]=ans[i*3+3]=1;
			if(B-C==-3)
				ans[i*3+2]=ans[i*3+3]=1;
		}
	}
	query(ans);
	return 0;
}