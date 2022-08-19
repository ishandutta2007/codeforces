#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define maxn 1000005
#define maxs 1000
#define ll long long

using namespace std;
int sz[maxn], p[maxn];
int cnt[maxn];
int n;
int main()
{
	scanf("%d", &n);
	//sz[1] = 1;
	for(int i = 2; i <= n; i++)
		scanf("%d", &p[i]);//, sz[i] = 1;
	for(int i = n; i >= 1; i--)
	{
		if(!sz[i]) sz[i] = 1;
		sz[p[i]] += sz[i];
		cnt[sz[i]]++;
	}
	for(int i = 1; i <= n; i++)
		cnt[i] += cnt[i - 1];
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = n;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(cnt[mid] >= i) r = mid;
			else l = mid + 1;
		}
		printf("%d ", l);
	}
	return 0;
}