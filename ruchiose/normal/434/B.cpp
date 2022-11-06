#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 1010;

int N, M, Q;
int A[MAXN][MAXN];
int U[MAXN][MAXN], D[MAXN][MAXN], L[MAXN][MAXN], R[MAXN][MAXN];

void Initialize()
{
	int i, j;
	fortodo(i, 0, N + 1)
		fortodo(j, 0, M + 1)
			U[i][j] = D[i][j] = L[i][j] = R[i][j] = 0;
	fortodo(i, 1, N)
		fortodo(j, 1, M)
			if (A[i][j])
				U[i][j] = U[i - 1][j] + 1;
			else
				U[i][j] = 0;
	for (i = N; i; i--)
		fortodo(j, 1, M)
			if (A[i][j])
				D[i][j] = D[i + 1][j] + 1;
			else
				D[i][j] = 0;
	fortodo(i, 1, M)
		fortodo(j, 1, N)
			if (A[j][i])
				L[j][i] = L[j][i - 1] + 1;
			else
				L[j][i] = 0;
	for (i = M; i; i--)
		fortodo(j, 1, N)
			if (A[j][i])
				R[j][i] = R[j][i + 1] + 1;
			else
				R[j][i] = 0;
}

void Repair(int y, int z)
{
	int i, j;
	fortodo(i, y, N)
		if (A[i][z])
			U[i][z] = U[i - 1][z] + 1;
		else
			U[i][z] = 0;
	for (i = y; i; i--)
		if (A[i][z])
			D[i][z] = D[i + 1][z] + 1;
		else
			D[i][z] = 0;
	fortodo(i, z, M)
		if (A[y][i])
			L[y][i] = L[y][i - 1] + 1;
		else
			L[y][i] = 0;
	for (i = z; i; i--)
		if (A[y][i])
			R[y][i] = R[y][i + 1] + 1;
		else
			R[y][i] = 0;
}

struct Incstack
{
	int S;
	int V[MAXN], H[MAXN];
	void Init()
	{
		S = 0;
	}
	void Insert(int nV, int nH)
	{
		while ((S) && (V[S] >= nV)) S--;
		++S;
		V[S] = nV; H[S] = nH;
	}
	int Minor()
	{
		return (S == 1) ? 0 : H[S - 1];
	}
};

int Inf[MAXN], Sup[MAXN];
Incstack Is;

int Query(int y, int z)
{
	int ans = 0, i;
	//  U
	Is.Init(); Is.Insert(0, 0);
	fortodo(i, 1, M)
		{
			Is.Insert(U[y][i], i);
			Inf[i] = Is.Minor() + 1;
		}
	Is.Init(); Is.Insert(0, M + 1);
	for (i = M; i; i--)
		{
			Is.Insert(U[y][i], i);
			Sup[i] = Is.Minor() - 1;
		}
	fortodo(i, 1, M)
		if ((z >= Inf[i]) && (z <= Sup[i]))
			ans = max(ans, (Sup[i] - Inf[i] + 1) * U[y][i]);
	//  D
	Is.Init(); Is.Insert(0, 0);
	fortodo(i, 1, M)
		{
			Is.Insert(D[y][i], i);
			Inf[i] = Is.Minor() + 1;
		}
	Is.Init(); Is.Insert(0, M + 1);
	for (i = M; i; i--)
		{
			Is.Insert(D[y][i], i);
			Sup[i] = Is.Minor() - 1;
		}
	fortodo(i, 1, M)
		if ((z >= Inf[i]) && (z <= Sup[i]))
			ans = max(ans, (Sup[i] - Inf[i] + 1) * D[y][i]);
	//  L
	Is.Init(); Is.Insert(0, 0);
	fortodo(i, 1, N)
		{
			Is.Insert(L[i][z], i);
			Inf[i] = Is.Minor() + 1;
		}
	Is.Init(); Is.Insert(0, N + 1);
	for (i = N; i; i--)
		{
			Is.Insert(L[i][z], i);
			Sup[i] = Is.Minor() - 1;
		}
	fortodo(i, 1, N)
		if ((y >= Inf[i]) && (y <= Sup[i]))
			ans = max(ans, (Sup[i] - Inf[i] + 1) * L[i][z]);
	//  R
	Is.Init(); Is.Insert(0, 0);
	fortodo(i, 1, N)
		{
			Is.Insert(R[i][z], i);
			Inf[i] = Is.Minor() + 1;
		}
	Is.Init(); Is.Insert(0, N + 1);
	for (i = N; i; i--)
		{
			Is.Insert(R[i][z], i);
			Sup[i] = Is.Minor() - 1;
		}
	fortodo(i, 1, N)
		if ((y >= Inf[i]) && (y <= Sup[i]))
			ans = max(ans, (Sup[i] - Inf[i] + 1) * R[i][z]);
	return ans;
}

int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	int q, i, j, x, y, z;
	fortodo(i, 1, N)
		fortodo(j, 1, M)
			scanf("%d", &A[i][j]);
	Initialize();
	fortodo(q, 1, Q)
		{
			scanf("%d%d%d", &x, &y, &z);
			if (x == 1)
				{
					A[y][z] ^= 1;
					Repair(y, z);
				}
			else
				printf("%d\n", Query(y, z));
		}
}