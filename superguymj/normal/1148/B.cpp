#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
int n,m,ans,A,B,k,a[N],b[N];

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&A,&B,&k);
	rep(i,1,n) scanf("%d",&a[i]),a[i]+=A;
	rep(i,1,m) scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int p=0;
	if(n<=k) return puts("-1"),0;
	rep(i,1,k+1)
	{
		while(p+1<=m && b[p+1]<a[i]) ++p;
		if(p+k-(i-1)>=m) return puts("-1"),0;
		ans=max(ans,b[p+k-(i-1)+1]);
	}
	printf("%d\n",ans+B);
	return 0;
}