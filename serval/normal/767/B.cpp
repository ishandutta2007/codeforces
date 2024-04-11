#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int n;
long long ts,tf,t;
long long s[N];
long long waiting,cw,aw,at,lt;
int cur;
int main()
{
	scanf("%lld%lld%lld",&ts,&tf,&t);
	scanf("%d",&n);
	tf-=t-1;
	for (int i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	while (s[n]>tf)
		n--;
	s[++n]=tf;
	aw=(long long)1e13;
	for (int i=1;i<=n;i=cur)
	{
		if (s[i]-1>=ts)
			cw=max(0ll,waiting-(s[i]-1-max(lt,ts)));
		else
			cw=waiting+ts-s[i]+1;
		if (cw<aw&&s[i]-1+cw<=tf)
		{
			aw=cw;
			at=s[i]-1;
		}
		if (s[i]>=ts)
			waiting=max(0ll,waiting-(s[i]-max(lt,ts)));
		cur=i;
		lt=s[cur];
		while (s[cur]==s[i])
		{
			waiting+=t;
			cur++;
		}
	}
	printf("%lld\n",at);
	return 0;
}