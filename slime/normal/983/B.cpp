#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 5005
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
int a[maxn];
int ans[maxn][maxn];
int mxs[maxn][maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
		{
			for(int k = (j - i); 1; k = (k - 1) & (j - i))
			{
				ans[i][j] ^= a[i + k];
				if(k == 0) break;
			}
		}
//	cout<<ans[3][6]<<endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n - i + 1; j++)
			mxs[j][j + i - 1] = max(mxs[j][j + i - 2], mxs[j + 1][j + i - 1]), 
			mxs[j][j + i - 1] = max(mxs[j][j + i - 1], ans[j][j + i - 1]);
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", mxs[l][r]);
	}
	return 0;
}