#include <bits/stdc++.h>
using namespace std;

const int N = 5000011;
int pre[N];

int main()
{
	//ios :: sync_with_stdio(false);
	for(int i = 2; i < N; i ++)
		if(pre[i] == 0)
			for(int j = i; j < N; j += i)
				for(int k = j; k % i == 0; k /= i)
					pre[j] ++;

	for(int i = 1; i < N; i ++)
		pre[i] += pre[i - 1];

	int t;
	scanf("%d", &t);
	while(t --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", pre[a] - pre[b]);
	}
	return 0;
}