#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
 
using namespace std;
const int N=100005;
char s[N],t[N];
int n,a[2][2],ans;
 
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
 
void solve()
{
	n=getint(),scanf("%s",s+1),scanf("%s",t+1);
	a[0][0]=1,a[0][1]=a[1][0]=2,a[1][1]=0;
	int c=a[s[1]-48][t[1]-48];
	ans=0;
	rep(i,2,n)
	{
		int d=a[s[i]-48][t[i]-48];
		if(c==2) ans+=c,c=d;
		else if(c==1)
		{
			if(d==0) c=2;
			else ans+=c,c=d;
		}
		else
		{
			if(d==0 || d==2) ans+=c,c=d;
			else c=2;
		}
	}
	ans+=c;
	printf("%d\n",ans);
}
 
int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}