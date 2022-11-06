#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i;
i64 Sum, Max;

int main()
{
	scanf("%d", &N);
	Sum = Max = 0;
	fortodo(i, 1, N)
		{
			int u;
			scanf("%d", &u);
			Sum += u;
			Max = max(Max, (i64)u);
		}
	cout << max(Max, (Sum + N - 2) / (N - 1)) << endl;
}