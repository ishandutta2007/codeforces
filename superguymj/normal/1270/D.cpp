#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=505;
int n,k,a[N];

int query(int x)
{
	printf("?");
	rep(i,1,k+1) if(i!=x) printf(" %d",i);
	puts(""),fflush(stdout);
	int y;
	scanf("%d%d",&x,&y);
	return y;
}

void solve()
{
	scanf("%d%d",&n,&k);
	rep(i,1,k+1)
		a[i]=query(i);
	sort(a+1,a+k+2);
	int ans=k+1;
	rep(i,1,k+1)
		if(--ans,a[i]!=a[i+1]) break;
	printf("! %d\n",ans);
}

int main()
{
	solve();
	return 0;
}