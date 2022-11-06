/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

int N, M, a[100005];
vector<int>	S[100005];

inline LL	work(int x, vector<int>	S)
{
	if (!S.size())	return 0;
	sort(S.begin(), S.end());
	int y = S[S.size() / 2];
	LL	now = 0;
	for (int i = 0; i < S.size(); ++ i)
		now -= abs(x - S[i]) - abs(y - S[i]);
	return now;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	int tmp = read();
	LL sum = 0;
	for (int i = 1; i <= tmp; ++ i)
	{
		a[++ M] = read();
		if (M > 1 && a[M] == a[M - 1])	M --;
	}
	for (int i = 1; i <= M; ++ i)
	{
		if (i > 1)	S[a[i]].push_back(a[i - 1]);
		if (i < M)	S[a[i]].push_back(a[i + 1]);
	}
	for (int i = 1; i < M; ++ i)	sum += abs(a[i + 1] - a[i]);
	LL ans = sum;
	for (int i = 1; i <= N; ++ i)
	{
		ans = min(sum + work(i, S[i]), ans);
	}
	cout << ans << endl;
	

	return 0;
}