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
int n;
int tx[]={1,0,1};
int ty[]={0,1,1};
char s[101][101];
string a="theseus";
bool ok(int x,int y)
{
	if(s[x][y]!='t')
		return 0;
	for(int i=0;i<3;i++)
	{
		int xx=x,yy=y,ok=1;
		for(int l=1;l<7;l++)
		{
			xx+=tx[i];
			yy+=ty[i];
			if(xx&&yy&&xx<=n&&yy<=n&&s[xx][yy]==a[l])
				continue;
			ok=0;
			break;
		}
		if(ok)
			return 1;
	}
	return 0;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			if(ok(i,l))
			{
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}