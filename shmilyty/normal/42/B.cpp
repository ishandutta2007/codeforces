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
int a[8][8];
int tx[]={0,1,0,-1};
int ty[]={1,0,-1,0};
array<int,2> r[2],k1,k2;
void get(array<int,2> &x)
{
	string s;
	cin>>s;
	x={s[0]-'a',s[1]-'1'};
}
bool ok(int x,int y)
{
	return (x>=0&&y>=0&&x<8&&y<8);
}
signed main()
{
	get(r[0]);
	get(r[1]);
	get(k1);
	get(k2);
	for(int j=0;j<2;j++)
	for(int i=0;i<4;i++)
	{
		int x=r[j][0],y=r[j][1];
		a[x][y]--;
		while(1)
		{
			a[x][y]++;
			if(x==k1[0]&&y==k1[1])
				break;
			x+=tx[i];
			y+=ty[i];
			if(!ok(x,y))
				break;
		}
	}
	for(int i=-1;i<2;i++)
		for(int l=-1;l<2;l++)
		{
			if(i==0&&l==0)
				continue;
			int x=k1[0]+i,y=k1[1]+l;
			if(ok(x,y))
				a[x][y]++;
		}
	for(int i=-1;i<2;i++)
		for(int l=-1;l<2;l++)
		{
			int x=k2[0]+i,y=k2[1]+l;
			if(!ok(x,y))
				continue;
			if(a[x][y])
				continue;
			puts("OTHER");
			return 0;
		}
	puts("CHECKMATE");
	return 0;
}