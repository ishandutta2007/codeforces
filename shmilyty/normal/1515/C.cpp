#pragma GCC optimize ("Ofast")
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
struct node{
	int to,val;
	bool operator<(const node &x)const
	{
		return val==x.val?to<x.to:val<x.val;
	}
}w[100001];
int t,n,m,x,pos[100001];
set<node> s;
void solve()
{
	n=read();
	m=read();
	x=read();
	s.clear();
	for(int i=1;i<=n;i++)
		w[i]=(node){i,read()};
	sort(w+1,w+1+n);
	for(int i=1;i<=m;i++)
		s.insert((node){i,0});
	for(int i=n;i>=1;i--)
	{
//		cout<<w[i].to<<endl;
		node now=*s.begin();
		s.erase(now);
//		cout<<now.to<<" "<<now.val<<endl;
		now.val+=w[i].val;
		pos[w[i].to]=now.to;
		s.insert(now);
	}	
	node fir=*s.begin();
	node sec=*(s.rbegin());
	if(fir.val+x<sec.val)
	{
		puts("NO");
		return ;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		cout<<pos[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}