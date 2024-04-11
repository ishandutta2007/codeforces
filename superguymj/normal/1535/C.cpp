#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=200005;
char s[N];
int n,cnt[N][4],a[4];
typedef long long LL;
LL ans;

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
	scanf("%s",s+1),n=strlen(s+1),ans=0;
	rep(i,0,n) rep(j,0,3) cnt[i][j]=0;
	rep(i,1,n)
	{
		rep(j,0,3) cnt[i][j]=cnt[i-1][j];
		
		if(s[i]!='?')
		{
			int c=(s[i]&1)|((i&1)<<1);
			++cnt[i][c];
		}
	}
	rep(i,1,n)
	{
		int l=0,r=i-1;
		while(l<=r)
		{
			rep(j,0,3) a[j]=cnt[i][j]-cnt[mid][j];
			if((a[0] && a[2]) || (a[1] && a[3]) || (a[0] && a[1]) || (a[2] && a[3])) l=mid+1;
			else r=mid-1;
		}
		++r;
		ans+=i-r;
	}
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}