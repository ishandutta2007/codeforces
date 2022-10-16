#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N];
char t[N];

char ss[N];
int sl[N], sr[N], sc;
char tt[N];
int tl[N], tr[N], tc;

long long ans;

long long solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	sc = tc = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] != s[i - 1])
		{
			sc++;
			ss[sc] = s[i];
			sl[sc] = sr[sc] = i;
		}
		else
			sr[sc] = i;
	for (int i = 1; i <= n; i++)
		if (t[i] != t[i - 1])
		{
			tc++;
			tt[tc] = t[i];
			tl[tc] = tr[tc] = i;
		}
		else
			tr[tc] = i;
	if (sc != tc)
		return -1;
	ans = 0;
	for (int i = 1; i <= sc; i++)
	{
		if (ss[i] != tt[i])
			return -1;
		ans += abs(sl[i] - tl[i]) + abs(sr[i] - tr[i]);
	}
	return ans / 2;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		printf("%lld\n", solve());
	return 0;
}