#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0, f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int M = 100016, MOD = 1000000007;
const int MAXN = 2e6 + 5, INF = 1e9;

int t, n;
map<int, int> mp;

namespace solve
{
	int ans;

	void init()
	{
		ans = INF;
	}

	void check(int x)
	{
		int tmp = 0;
		for (auto p : mp)
		{
			if (p.second % (x - 1) > p.second / (x - 1))
				return;
			if (p.second % x == 0)
				tmp += p.second / x;
			else
				tmp += p.second / x + 1;
		}
		ans = min(ans, tmp);
	}

	int solve()
	{
		int lim = INF;
		for (auto p : mp)
			lim = min(p.second, lim);
		++lim;
		for (int i = 2; i <= lim; ++i)
			check(i);
		return ans;
	}
}

void init()
{
	mp.clear();
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		++mp[tmp];
	}
}

int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif

	scanf("%d", &t);
	while (t--)
	{
		init();
		solve::init();
		printf("%d\n", solve::solve());
	}

	return 0;
}