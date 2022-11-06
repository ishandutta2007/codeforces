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

#include<deque>

const i64 MOD[2] = {999990991, 999990997};

typedef pair<i64,i64> MSG;

char _ch[2][50050], *ch, *nx;
int N;

MSG operator + (MSG lhs, MSG rhs)
{
	return make_pair((lhs.first + rhs.first) % MOD[0], (lhs.second + rhs.second) % MOD[1]);
}

MSG operator - (MSG lhs, MSG rhs)
{
	return make_pair((lhs.first + MOD[0] - rhs.first) % MOD[0], (lhs.second + MOD[1] - rhs.second) % MOD[1]);
}

MSG operator * (MSG lhs, MSG rhs)
{
	return make_pair((lhs.first * rhs.first) % MOD[0], (lhs.second * rhs.second) % MOD[1]);
}

MSG pre[50050], pow26[50050];

void makeHash()
{
	pre[0] = make_pair(0, 0);
	int i;
	fortodo(i, 1, N) pre[i] = pre[i - 1] * pow26[1] + make_pair(ch[i] - 'a', ch[i] - 'a');
}

MSG	Sub(int l, int r)
{
	return pre[r] - pre[l - 1] * pow26[r - l + 1];
}

int LCP(int x, int y)
{
	if (ch[x] != ch[y])
		return 0;
	int L = 1, R = N - max(x, y) + 1;
	while (L < R)
		{
			int Mid = (L + R + 1) / 2;
			if (Sub(x, x + Mid - 1) == Sub(y, y + Mid - 1))
				L = Mid;
			else
				R = Mid - 1;
		}
	return L;
}

int LCS(int x, int y)
{
	if (ch[x] != ch[y])
		return 0;
	int L = 1, R = min(x, y);
	while (L < R)
		{
			int Mid = (L + R + 1) / 2;
			if (Sub(x - Mid + 1, x) == Sub(y - Mid + 1, y))
				L = Mid;
			else
				R = Mid - 1;
		}
	return L;
}

bool dexist(int l)
{
	for (int i = l; i + l < N; i += l)
		if (LCS(i, i + l) + LCP(i + 1, i + l + 1) >= l)
			return true;
	for (int i = l * 2; i <= N; i += l)
		if (LCS(i, i - l) >= l)
			return true;
	return false;
}

int D[50050];

int Nx(int x)
{
	while ((x <= N) && (D[x])) x += D[x];
	return x;
}

void process(int l)
{
	int i;
	fortodo(i, 1, N) D[i] = 0;
	for (i = l * 2; i <= N; )
		if (Sub(i - l * 2 + 1, i - l) == Sub(i - l + 1, i))
			{
				D[i - l + 1] = l;
				i += l;
			}
		else
			i++;
	int nxN = 0;
	for (i = Nx(1); i <= N; i = Nx(i + 1))
		nx[++nxN] = ch[i];
	swap(ch, nx);
	N = nxN;
}

int main()
{
	ch = _ch[0]; nx = _ch[1];
	scanf("%s", ch + 1);
	N = strlen(ch + 1);
	pow26[0] = make_pair(1, 1);
	pow26[1] = make_pair(26, 26);
	int i;
	fortodo(i, 2, N) pow26[i] = pow26[i - 1] * pow26[1];
	makeHash();
	fortodo(i, 1, (N >> 1))
		if (dexist(i))
			process(i), makeHash();
	ch[N + 1] = 0;
	printf("%s", ch + 1);
}