#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
int n,a[200005];
int tot1,tot2;
int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) if(a[i]==2) ++tot2;
	tot1=n-tot2;
	if(tot2>=tot1)
	{
		printf("%d\n",tot1);
		return 0;
	}
	printf("%d\n",tot2+(tot1-tot2)/3);
	return 0;
}