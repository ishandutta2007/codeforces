#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

#define maxn 1005

typedef long long ll;

const int MD = 1000000007;
int n, ans, pow[2 * maxn];
char s[maxn];

int main() 
{
	scanf(" %s", s);
	n = strlen(s);
	ans = 0;
	pow[0] = 1;
	for (int i = 1; i <= 2 * n; ++i)
	{
		pow[i] = (pow[i - 1] + pow[i - 1]) % MD;
	}
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '1')
		{
			ans = (ans + (ll)pow[i] * pow[2 * (n - 1 - i)]) % MD;
		}
	}
	printf("%d\n", ans);
	return 0;
}