#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int a[maxn], b[maxn];
int fl[maxn];
int tm[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++)
		cin>>b[i];
	for(int j = 1; j <= n; j++)
		if(b[j] == 1)
		{
			/*check1*/
			int nfl = 1;
			for(int k = j + 1; k <= n; k++)
				if(k - j + 1 != b[k]) nfl = 0;
			int ls = 1 + n - j;
			for(int i = 1; i <= n; i++)
				fl[a[i]] = 1;
			for(int s = 1; s < j; s++)
			{
				if(!fl[ls + s]) nfl = 0;
				fl[b[s]] = 1;
			}
			if(nfl)
			{
				cout<<n - ls<<endl;
				return 0;
			}
		}
	for(int j = 1; j <= n; j++)
		tm[a[j]] = 0;
	for(int j = 1; j <= n; j++)
		tm[b[j]] = j;
	int ans = 0;
	for(int j = 1; j <= n; j++)
		ans = max(ans, (n + 1 - j) + tm[j]);
	printf("%d\n", ans);
	return 0;
}