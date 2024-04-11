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
int t,n,m,xl,xr,yl,yr;
char s[1000001];
void chmx(int &x,int y)
{
	if(x<y)
		x=y;
}
void chmn(int &x,int y)
{
	if(x>y)
		x=y;
}
bool cmp(int l1,int r1,int l2,int r2)
{
//	cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
	if(xr<l1||r1<xl||yr<l2||r2<yl)
		return 0;
	chmx(xl,l1);
	chmn(xr,r1);
	chmx(yl,l2);
	chmn(yr,r2);
	return 1;
}
bool work(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	if(x>=1&&y>=1)
		return cmp(1,n-x+1,1,m-y+1);
	elif(x>=1&&y<1)
		return cmp(1,n-x+1,1-y+1,m);
	elif(x<1&&y>=1)
		return cmp(1-x+1,n,1,m-y+1);
	return cmp(1-x+1,n,1-y+1,m);
}
void solve()
{
	n=read();
	m=read();
	scanf("%s",s+1);
	xl=1,xr=n,yl=1,yr=m;
	int x=1,y=1,len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='U')
			x--;
		elif(s[i]=='D')
			x++;
		elif(s[i]=='L')
			y--;
		else
			y++;
		if(!work(x,y))
		{
			
//	cout<<xl<<" "<<xr<<" "<<yl<<" "<<yr<<endl;
//			cout<<xl<<" "<<yl<<endl;
			printf("%lld %lld\n",xl,yl);
			return ;
		}
	}
	printf("%lld %lld\n",xl,yl);
//	cout<<xl<<" "<<yl<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}