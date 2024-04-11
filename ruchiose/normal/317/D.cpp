#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map> 
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j, cntlyr, door[35];
const int SG[30] =
{0, 
1, 2, 1, 4, 3, 2, 1, 5, 6, 2,
1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 
4, 2, 1, 10, 9, 3, 6, 11, 12};

bool Greater(int a, int b)
{
	return a > b;
}

inline int lyr(int x)
{
	return upper_bound(door + 1, door + cntlyr + 1, x, Greater) - door - 1;
}

int memo[100010];

int main()
{
	scanf("%d", &N);
	fortodo(cntlyr, 1, 30)
		if ((door[cntlyr] = int(pow(N, 1.0 / cntlyr) + 1e-8)) == 1)
			break;
	cntlyr--;
	int Sg = 1;
	fortodo(i, 2, door[2]) memo[i] = 0;
	fortodo(i, 1, cntlyr)
		if ((door[i] ^ door[i + 1]) & 1)
			Sg ^= SG[i];
	fortodo(i, 2, door[2])
		if (memo[i] == 0)
			for (i64 j = i * i; j <= N; j *= i)
				{
					int j32 = j;
					if (j32 <= door[2]) memo[j32] = 1;
					Sg ^= SG[lyr(j32)];
				}
	if (Sg)
		printf("Vasya\n");
	else
		printf("Petya\n");
}