#include <iostream>
#include <vector>

using namespace std;

int n, a, b;
int h[20];
int hit[20];

int p[20];
bool have;

void rec(int k, int s)
{
	if (have) return ;
	if (k == n - 2) 
	{
		p[n - 1] = s;
		bool good = true;
		for (int i = 2; i <= n - 1; i ++)
			if (h[i] >= p[i - 1] * b + p[i + 1] * b + p[i] * a) {good = false; break;}
		if (good)
		{
			have = true;
			for (int i = 2; i <= n - 1; i ++)
				hit[i] += p[i];
			return ;
		}
		return ;
	}
	for (int i = 0; i <= s && !have; i ++)
		p[k + 1] = i, rec(k + 1, s - i);
}

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &h[i]);
	while (h[1] >= 0)
		h[1] -= b, hit[2] ++, h[2] -= a, h[3] -= b, hit[1] ++;
	while (h[n] >= 0)
		h[n] -= b, hit[n - 1] ++, h[n - 1] -= a, h[n - 2] -= b, hit[n] ++;

	have = false;

	for (int i = 0; ; i ++)
	{
		rec(1, i);
		if (have)
		{
			printf("%d\n", i + hit[1] + hit[n]);
			for (int j = 2; j <= n - 1; j ++)
				for (int k = 1; k <= hit[j]; k ++)
					printf("%d ", j);
			printf("\n");
			return 0;
		}
	}


	return 0;
}