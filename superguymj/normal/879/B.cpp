#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,a[505],ans,nxt[505];
long long k,p[505];

int main()
{
	scanf("%d%I64d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]),ans=max(ans,a[i]);
	rep(i,1,n) nxt[i]=n+1;
	rep(i,1,n)
		rep(j,i+1,n)
			if(a[i]<a[j])
			{
				nxt[i]=j;
				break;
			}
	for(int i=1,j; i<=n; i=j)
	{
		if(a[j]==n) break;
		j=nxt[i];
		p[i]+=j-i-1;
		if(p[i]>=k) {ans=a[i]; break;}
		else ++p[j];
	}
	printf("%d\n",ans);
	return 0;
}