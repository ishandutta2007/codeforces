#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,a[200005],R;

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n-1)
	{
		if(a[i]==a[i+1]) return puts("NO");
		if(a[i]+1!=a[i+1] && a[i]-1!=a[i+1])
		{
			if(R && abs(a[i]-a[i+1])!=R) return puts("NO"),0;
			else R=abs(a[i]-a[i+1]);
		}
	}
	if(!R) return puts("YES"),puts("1 1000000000"),0;
	rep(i,1,n-1)
	{
		if(a[i]+1==a[i+1] && a[i]%R==0) return puts("NO"),0;
		if(a[i]-1==a[i+1] && a[i]%R==1) return puts("NO"),0;
	}
	puts("YES");
	printf("1000000000 %d\n",R);
	return 0;
}