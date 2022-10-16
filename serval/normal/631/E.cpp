#include <cstdio>
#include <algorithm>
using namespace std;
long long n,i;
long long v[200005],pre[200005],suf[200005];
long long q[200005],l,r;
long long res,preans,sufans;
int main()
{
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
		res+=i*v[i];
		pre[i]=pre[i-1]+v[i];
	}
	for (i=n;i;i--)
		suf[i]=suf[i+1]-v[i];
	l=1;
	r=0;
	for (i=1;i<=n;i++)
	{
		while (l<r&&(v[q[l+1]]-v[q[l]])*i>v[q[l+1]]*q[l+1]-v[q[l]]*q[l]+pre[q[l]]-pre[q[l+1]])
			l++;
		if (l<=r&&v[q[l]]*(i-q[l])-pre[i]+pre[q[l]]>preans)
			preans=v[q[l]]*(i-q[l])-pre[i]+pre[q[l]];
		while (l<r&&(v[q[r]]-v[q[r-1]])*(v[i]*i-v[q[r]]*q[r]+pre[q[r]]-pre[i])<=(v[i]-v[q[r]])*(v[q[r]]*q[r]-v[q[r-1]]*q[r-1]+pre[q[r-1]]-pre[q[r]]))
			r--;
		q[++r]=i;
	}
	l=1;
	r=0;
	for (i=n;i;i--)
	{
		while (l<r&&(v[q[l+1]]-v[q[l]])*i>v[q[l+1]]*q[l+1]-v[q[l]]*q[l]+suf[q[l]]-suf[q[l+1]])
			l++;
		if (l<=r&&v[q[l]]*(i-q[l])-suf[i]+suf[q[l]]>sufans)
			sufans=v[q[l]]*(i-q[l])-suf[i]+suf[q[l]];
		while (l<r&&(v[q[r]]-v[q[r-1]])*(v[i]*i-v[q[r]]*q[r]+suf[q[r]]-suf[i])>=(v[i]-v[q[r]])*(v[q[r]]*q[r]-v[q[r-1]]*q[r-1]+suf[q[r-1]]-suf[q[r]]))
			r--;
		q[++r]=i;
	}
	res+=max(preans,sufans);
	printf("%lld\n",res);
	return 0;
}