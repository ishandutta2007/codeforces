#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int T,n,x,ans[N],p[N];
char s[N];

void turn(int x)
{
	if(1<=x && x<=n) ans[x]=0;
}

bool Q(int x)
{
	if(1<=x && x<=n) return ans[x];
	return 0;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1),n=strlen(s+1);
		scanf("%d",&x);
		rep(i,1,n) ans[i]=1;
		rep(i,1,n) if(s[i]=='0') turn(i-x),turn(i+x);
		rep(i,1,n) p[i]=Q(i-x)|Q(i+x);
		bool jdg=0;
		rep(i,1,n) if(p[i]!=s[i]-'0') jdg=1;
		if(jdg) puts("-1");
		else
		{
			rep(i,1,n) printf("%d",ans[i]);
			puts("");
		}
	}
	return 0;
}