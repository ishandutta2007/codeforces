// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M;
i64 ANS;

int main()
{
	scanf("%d%d", &N, &M);
	ANS = 0;
	int i, j, L = M + 1, R = N - M, A = N + 1;
	fortodo(i, L, (L + R) / 2)
		{
			int SUBANS = 0;
			int _R = min(R, 2 * A);
			fortodo(j, L, _R)
				{
					int H = ((2 * i - j) * (A - i) - 1) / (i + j);
					if (H >= R)
						SUBANS += R - L + 1;
					else
						if (H >= L)
							SUBANS += H - L + 1;
				}
			if (i == A - i)
				ANS += 3LL * SUBANS;
			else
				ANS += 6LL * SUBANS;
		}
	cout << ANS << endl;
}