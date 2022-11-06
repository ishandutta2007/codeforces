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

int N;
bool	a[50005];
int f[55] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 13};

/*
short sg[1 << 29];
int mex[105];

inline int	Prepare(int N)
{
	sg[0] = 0;
	int ans;
	for (int i = 1; i < 1 << N; ++ i)
	{
		for (int j = 1; j <= N; ++ j)	if (i & (1 << j - 1))
		{
			int l = i;
			for (int k = j; k <= N; k += j)
				if (l & (1 << k - 1))
					l ^= 1 << k - 1;
			mex[sg[l]] = i;
		}
		for (int j = 0; ; ++ j)
			if (mex[j] != i)
			{
				sg[i] = j;
				break;
			}
		ans = sg[i];
	}
	cout << N << " " << ans << endl;
	return ans;
}
*/
int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif

	//for (int i = 28; i <= 29; ++ i)	f[i] = Prepare(i);
	N = read();
	int R = N;
	int M = sqrt(N) + 1;
	int ans = 1;
	R --;
	for (int i = 2; i <= M; ++ i)
		if (i * i <= N && !a[i])
		{
			int tot = 0;
			for (LL j = i; j <= N; j *= LL(i))
			{
				++ tot;
				if (j <= M)	a[j] = 1;
			}
			R -= tot;
			ans ^= f[tot];
		}
	ans ^= R & 1;
	if (ans)	printf("Vasya\n");
	else	printf("Petya\n");

	return 0;
}