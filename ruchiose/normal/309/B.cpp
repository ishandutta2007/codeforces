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

const int MAXN = 1000010;

int N, R, C;
int A[MAXN], MR[MAXN];
string s[MAXN];
int mt[MAXN], mlv[MAXN][20];

void printAd(int x)
{
	int i, j;
	fortodo(i, 1, R)
		{
			fortodo(j, x, mt[x] - 1)
				{
					if (j != x) putchar(' ');
					cout << s[j];
				}
			cout << endl;
			x = mt[x];
			if (x > N) break;
		}
}

int main()
{
	scanf("%d%d%d", &N, &R, &C);
	int i, k;
	fortodo(i, 1, N)
		{
			cin >> s[i];
			A[i] = s[i].size() + 1;
		}
	int Sum = -1, r = 1;
	fortodo(i, 1, N)
		{
			while ((r <= N) && (Sum + A[r] <= C)) Sum += A[r++];	
			mt[i] = r;
			Sum -= A[i];
		}
	mt[N + 1] = N + 1;
	fortodo(i, 1, N + 1) mlv[i][0] = mt[i];
	fortodo(k, 1, 19)
		fortodo(i, 1, N + 1)
			mlv[i][k] = mlv[mlv[i][k - 1]][k - 1];
	int ans = 0;
	fortodo(i, 1, N)
		{
			MR[i] = i;
			for (int t = R; t; t -= (t & -t)) MR[i] = mlv[MR[i]][__builtin_ctz(t)];
			ans = max(ans, MR[i] - i);
		}
	fortodo(i, 1, N)
		if (ans == MR[i] - i)
			{
				printAd(i);
				return 0;
			}
}