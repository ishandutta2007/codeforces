#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 50010

char s[maxn];
int n;

int main()
{
	scanf("%s", s);
	n = strlen(s);
	int cur = 1;
	while (cur <= n / 2)
	{
		int mlen = 0, i = 0;
		bool ok = false;
		for (i = 0; i < n - cur; ++i)
		{
			mlen = (s[i] == s[i + cur]) ? mlen + 1 : 0;
			if (mlen == cur)
			{
				ok = true;
				break;
			}
		}
		if (!ok)
		{
			++cur;
		}
		else
		{
			for (int j = i; j <= n - cur; ++j)
			{
				s[j] = s[j + cur];
			}
			n -= cur;
			cur = 1;
		}
	}
	printf("%s\n", s);
	return 0;
}