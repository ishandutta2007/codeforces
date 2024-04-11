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

const int MAXN = 100010;
typedef pair<int,int> PII;

bool operator < (PII lhs, PII rhs)
{
	return (lhs.first == rhs.first) ? (lhs.second < rhs.second) : (lhs.first < rhs.first);
}

int N;
PII Xs[MAXN], Ys[MAXN], X[MAXN], Y[MAXN];

int boxId[MAXN], szBox[MAXN];

int main()
{
	scanf("%d", &N);
	int i;
	fortodo(i, 1, N)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			X[i] = Xs[i] = make_pair(x, i);
			Y[i] = Ys[i] = make_pair(y, i);
		}
	sort(Xs + 1, Xs + N + 1);
	sort(Ys + 1, Ys + N + 1);
	i64 ans = 0;
	fortodo(i, 1, N / 2) ans -= 2ll * (Xs[i].first + Ys[i].first);
	fortodo(i, N - N / 2 + 1, N) ans += 2ll * (Xs[i].first + Ys[i].first);
	if (N % 2 == 0)
		{
			// no median
			fortodo(i, 1, N) boxId[i] = 0;
			fortodo(i, N / 2 + 1, N) boxId[Xs[i].second] |= 2;
			fortodo(i, N / 2 + 1, N) boxId[Ys[i].second] |= 1;
			int cntBoxes[2];
			cntBoxes[0] = cntBoxes[1] = 0;
			fortodo(i, 1, N) cntBoxes[__builtin_popcount(boxId[i]) & 1]++;
			if ((cntBoxes[0]) && (cntBoxes[1]))
				ans -= 2ll * min(Xs[N / 2 + 1].first - Xs[N / 2].first, Ys[N / 2 + 1].first - Ys[N / 2].first);
			cout << ans << endl;
			return 0;
		}
	if (Xs[N / 2 + 1].second == Ys[N / 2 + 1].second)
		{
			// 1 median
			fortodo(i, 1, N) boxId[i] = 0;
			fortodo(i, N - N / 2 + 1, N) boxId[Xs[i].second] |= 2;
			fortodo(i, N - N / 2 + 1, N) boxId[Ys[i].second] |= 1;
			int cntBoxes[2];
			cntBoxes[0] = cntBoxes[1] = 0;
			fortodo(i, 1, N)
				if (i != Xs[N / 2 + 1].second)
					cntBoxes[__builtin_popcount(boxId[i]) & 1]++;
			if ((cntBoxes[0]) && (cntBoxes[1]))
				ans -= 2ll * min(min(Xs[N / 2 + 1].first - Xs[N / 2].first,
									 Xs[N / 2 + 2].first - Xs[N / 2 + 1].first),
							     min(Ys[N / 2 + 1].first - Ys[N / 2].first,
							   	     Ys[N / 2 + 2].first - Ys[N / 2 + 1].first));
			cout << ans << endl;
			return 0;
		}
	cout << ans << endl;
}