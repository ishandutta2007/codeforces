#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n,t[100001],l[100001],r[100001];
bitset<200002> cur,one;
map<int,int> comp,rev;
signed main()
{
	n=read();
	comp[1];
	for(int i=1;i<=n;i++)
	{
		t[i]=read();
		l[i]=read();
		r[i]=read()+1;
		comp[l[i]];
		comp[r[i]];
	}
	int nxt=0;
	for(auto &p:comp)
	{
		p.second=nxt++;
		rev[p.second]=p.first;
	}
	one=~one;
	cur=one;
	for(int i=1;i<=n;i++)
	{
		int T=t[i],L=comp[l[i]],R=comp[r[i]];
		switch(T)
		{
			case 1:{
				cur&=~(one>>(2*(1e5+1)+L-R)<<L);
				break;
			}
			case 2:{
				cur|=(one>>(2*(1e5+1)+L-R)<<L);
				break;
			}
			case 3:{
				cur^=(one>>(2*(1e5+1)+L-R)<<L);
				break;
			}
		}
		cout<<rev[cur._Find_first()]<<endl;
	}
	return 0;
}