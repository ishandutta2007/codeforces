#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1; char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef long long ll;
const int M = 100016, MOD = 1000000007;
int a[M], b[M], cnt[M], mx[M];
priority_queue<int, vector<int>, greater<int> > q;
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i)
	{
		++cnt[a[i]];
		if (mx[a[i]] == 0)
			mx[a[i]] = b[i];
		else
		{
			q.push(min(mx[a[i]], b[i]));
			mx[a[i]] = max(mx[a[i]], b[i]);
		}
	}
	ll tot = 0, ans = 0;
	for (int i = 1; i <= k; ++i)
		if (cnt[i] == 0)
			++tot;
	while (!q.empty() && tot--)
	{
		ans += q.top();
		q.pop();
	}
	printf("%lld", ans);

	return 0;
}