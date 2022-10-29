#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=205;
int n,a[N],b[N];
char s[10];

bool cmp(int x,int y)
{
	printf("? %d %d\n",x,y),fflush(stdout);
	scanf("%s",s);
	return s[0]=='<';
}

void solve()
{
	scanf("%d",&n);
	int x=(n+1)/2,y=n+1-x;
	rep(i,1,x) a[i]=i;
	rep(i,1,y) b[i]=x+i;
	sort(a+1,a+1+x,cmp);
	sort(b+1,b+1+y,cmp);
	rep(i,n+2,2*n)
	{
		if(cmp(a[1],b[1]))
		{
			a[1]=i;
			rep(j,1,x-1) if(!cmp(a[j],a[j+1])) swap(a[j],a[j+1]);
		}
		else
		{
			b[1]=i;
			rep(j,1,y-1) if(!cmp(b[j],b[j+1])) swap(b[j],b[j+1]);
		}
	}
	cmp(a[1],b[1]);
	puts("!"),fflush(stdout);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}