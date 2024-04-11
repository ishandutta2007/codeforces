#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 32768;

int n;
int f[N];

int main()
{
	for (int i = 0; i < N; i++)
		f[i] = N;
	f[0] = 0;
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < N; j++)
		{
			f[j] = min(f[j], f[(j + 1) % N] + 1);
			f[j] = min(f[j], f[(2 * j) % N] + 1);
		}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d%c", f[x], " \n"[i == n]);
	}
	return 0;
}