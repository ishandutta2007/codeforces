#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int MAXN = 3000 + 9;
const LL INF = 1000000000000000000LL;

int n, m;
LL ans = INF;
int cnt[MAXN];
int tcnt[MAXN];

inline int abs(int x)
{
	return x > 0 ? x : -x;
}

struct per{
	int a, c;
	bool ch;
	bool operator< (const per &_t) const
	{
		return c < _t.c;
	}
} ps[MAXN];

int main()
{
	int curc, ls;
	LL curans;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		scanf("%d%d", &ps[i].a, &ps[i].c);
		++cnt[ps[i].a];
	}
	sort(ps, ps + n);
	for(int i=0; i<=n; ++i)
	{
		curc = cnt[1] + i;
		ls = i;
		curans = 0;
		for(int i=1; i<=m; ++i) tcnt[i] = cnt[i];
		for(int j=0; j<n; ++j)
		{
			if(ps[j].a != 1 && tcnt[ps[j].a] >= curc)
			{
				--tcnt[ps[j].a];
				curans += ps[j].c;
				--ls;
				ps[j].ch = true;
			}
			else ps[j].ch = false;
		}
		for(int j=0; j<n && ls>0; ++j)
		{
			if(ps[j].a != 1 && !ps[j].ch)
			{
				curans += ps[j].c;
				--ls;
			}
		}
		if(curans < ans) ans = curans;
	}
	cout << ans << endl;
	
	return 0;
}