#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int MAXN = 2000 + 9;

int n, m;
int a[MAXN], b[MAXN];
LL mina[MAXN], minb[MAXN];
int ans;
LL maxsum;

int main()
{
	memset(mina, 0x3f, sizeof(mina));
	memset(minb, 0x3f, sizeof(minb));
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
		a[i] += a[i-1];
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", &b[i]);
		b[i] += b[i-1];
	}
	cin >> maxsum;
	for(int i=1; i<=n; ++i)
	{
		for(int j=i; j<=n; ++j)
		{
			if(a[j] - a[j-i] < mina[i])
				mina[i] = a[j] - a[j-i];
		}
	}
	for(int i=1; i<=m; ++i)
	{
		for(int j=i; j<=m; ++j)
		{
			if(b[j] - b[j-i] < minb[i])
				minb[i] = b[j] - b[j-i];
		}
	}
	int cur = m;
	for(int i=1; i<=n; ++i)
	{
		while(mina[i] * minb[cur] > maxsum) --cur;
		if(i * cur > ans) ans = i * cur;
	}
//	for(int i=1; i<=n; ++i)
//		cout << mina[i] << " ";
//	cout << endl;
//	for(int i=1; i<=m; ++i)
//		cout << minb[i] << " ";
//	cout << endl;
	
	printf("%d", ans);
	
	return 0;
}