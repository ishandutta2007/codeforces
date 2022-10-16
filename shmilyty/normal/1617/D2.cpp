#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int t,n,x,y,k,k1,a[30001];
int ask(int a,int b,int c)
{
	printf("? %d %d %d\n",a+1,b+1,c+1);
	cout.flush();
	return read(); 
}
vector<int> v;
void solve()
{
	n=read();
	for(int i=0;i<n;i+=3)
	{
		a[i]=ask(i,i+1,i+2);
		if(a[i])
			x=i;
		else
			y=i;
	}
	int tot=ask(x,x+1,y+1)+ask(x,x+1,y);
	if(tot==2)
		k1=x;
	else
		k1=x+2;
	tot=ask(x,y,y+1)+ask(x+1,y+1,y);
	if(!tot)
		k=y;
	else
		k=y+2;
	v.clear();
	v.push_back(k);
	for(int i=0;i<n;i+=3)
		if(i!=x&&i!=y)
		{
			int cnt=0;
			if(a[i])
			{
				cnt=(1-ask(i,i+1,k))+2*(1-ask(i+1,i+2,k));
				if(cnt==1)
					v.push_back(i);
				if(cnt==2)
					v.push_back(i+2);
				if(cnt==3)
					v.push_back(i+1);
			}
			else
			{
				cnt=ask(i,i+1,k1)+2*ask(i+1,i+2,k1);
				if(cnt==1)
				{
					v.push_back(i+1);
					v.push_back(i+2);
				}
				if(cnt==2)
				{
					v.push_back(i);
					v.push_back(i+1);
				}
				if(cnt==3)
				{
					v.push_back(i);
					v.push_back(i+2);
				}
				if(cnt==0)
				{
					v.push_back(i);
					v.push_back(i+1);
					v.push_back(i+2);
				}
			}
		}
		else
		{
			for(int l=0;l<3;l++)
				if(i+l!=k&&i+l!=k1)
					if(!ask(i+l,k,k1))
						v.push_back(i+l);
		}
	cout<<"! "<<v.size();
	for(int i:v)
		cout<<" "<<i+1;
	cout<<'\n';
	cout.flush();
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}