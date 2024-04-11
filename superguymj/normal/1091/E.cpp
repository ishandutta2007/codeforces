#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=500005;
typedef long long LL;
int n,d[N];
LL s[N];
int ans[N];

bool cmp(int x,int y) {return x>y;}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&d[i]);
	sort(d+1,d+1+n,cmp);
	rep(i,1,n) s[i]=s[i-1]+d[i];
	int L=0,R=n,p=n+1;
	rep(i,1,n)
	{
		while(p-1 && d[p-1]<=i) --p;
		int j=max(p,i+1);
		LL a=s[i],b=(j-i-1ll)*i+s[n]-s[j-1]+i*(i-1ll);
		if(a>b)
		{
			if(a-b>i) return puts("-1"),0;
			L=max((LL)L,a-b);
		}
		R=min((LL)R,d[i]+b+i-a);
	}
	rep(i,L,R) if(!((i^s[n])&1)) ans[++*ans]=i;
	if(!(*ans)) return puts("-1"),0;
	rep(i,1,*ans) printf("%d ",ans[i]);
	puts("");
	return 0;
}