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

const int MAXA = 100010;

int N, M;
int ox, oy, dx, dy;

int Go()
{
	int t = min((dx == 1) ? (N - ox) : (ox - 1), (dy == 1) ? (M - oy) : (oy - 1));
	ox += dx * t;
	oy += dy * t;
	return t;
}

int Vu[MAXA], Vd[MAXA], Vl[MAXA], Vr[MAXA], Task;

void TaskInitialize()
{
	int i, c = (ox + oy) & 1;
	Task = 0;
	fortodo(i, 1, M)
		{
			Vu[i] = 0;
			if ((1 + i) % 2 == c) Task++;
			Vd[i] = 0;
			if ((N + i) % 2 == c) Task++;
		}
	fortodo(i, 1, N)
		{
			Vl[i] = 0;
			if ((1 + i) % 2 == c) Task++;
			Vr[i] = 0;
			if ((M + i) % 2 == c) Task++;
		}
}

void Process(int &x)
{
	if (x == 3)
		{
			printf("-1\n");
			exit(0);
		}
	if (x == 0) Task--;
	x++;
}

void IAmHere()
{
	if (ox == 1) Process(Vu[oy]);
	if (ox == N) Process(Vd[oy]);
	if (oy == 1) Process(Vl[ox]);
	if (oy == M) Process(Vr[ox]);
}

void Reflect()
{
	if (ox == 1) dx = 1;
	if (ox == N) dx = -1;
	if (oy == 1) dy = 1;
	if (oy == M) dy = -1;
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &ox, &oy);
	char ch[3];
	scanf("%s", ch);
	dx = (ch[0] == 'U') ? -1 : 1;
	dy = (ch[1] == 'L') ? -1 : 1;
	/*
	Deleted, since it's guaranteed, the start point is on border.
	dx *= -1; dy *= -1;
	Go();
	dx *= -1; dy *= -1;
	*/
	TaskInitialize();
	i64 ans = 1;
	IAmHere();
	while (Task)
		{
			ans += Go();
			IAmHere();
			Reflect();
		}
	cout << ans << endl;
}