#include<bits/stdc++.h>
using namespace std;
#define LL long long
typedef struct Res
{
	int id;
	double x, v;
	bool operator < (const Res &b) const
	{
		if(fabs(x*b.v)<fabs(v*b.x))
			return 1;
		return 0;
	}
}Point;
Point s[100005];
int n, a[100005], b[100005], tre[100005];
int Query(int k)
{
	int ans = 0;
	while(k)
	{
		ans += tre[k];
		k -= k &-k;
	}
	return ans;
}
void Update(int k, int val)
{
	while(k<=n)
	{
		tre[k] += val;
		k += k&-k;
	}
}
int main(void)
{
	int i;
	LL ans;
	double w;
	scanf("%d%lf", &n, &w);
	w += 1e-6;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf", &s[i].x, &s[i].v);
		s[i].id = i, s[i].v -= w;
	}
	sort(s+1, s+n+1);
	for(i=1;i<=n;i++)
		a[i] = s[i].id;
	for(i=1;i<=n;i++)
		s[i].v += 2*w;
	sort(s+1, s+n+1);
	for(i=1;i<=n;i++)
		b[s[i].id] = i;
	ans = 0;
	for(i=1;i<=n;i++)
	{
		ans += i-1-Query(b[a[i]]);
		Update(b[a[i]], 1);
	}
	printf("%lld\n", ans);
	return 0;
}