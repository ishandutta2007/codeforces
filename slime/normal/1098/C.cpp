#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
int n;
ll s; 
int a[maxn];
bool check(int k, ll c, int b)
{
	a[1] = 1;
	k--, c--;
	for(int i = 2; i < maxn; i++)
	{
		if(c < 0) return 0;
		a[i] = 0;
		for(int j = 1; j <= 1ll * a[i - 1] * b && j <= k; j++)
		{
			if(1ll * j * i + 1ll * i * (k - j) + 1ll * (k - j) * (k - j + 1) / 2 >= c)
				a[i] = j;
			else break;
		}
		k -= a[i], 
		c -= 1ll * i * a[i];
	}
	if(c == 0) return 1;
	return 0;
}
int main()
{
	scanf("%d%lld", &n, &s);
	int l = 1, r = n - 1;
	if(!check(n, s, r)) 
	{
		cout<<"No"<<endl;
		return 0; 
	}
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(n, s, mid)) r = mid;
		else l = mid + 1;
	}
	check(n, s, l);
	int sum = 0;
	for(int i = 2; i < maxn; i++)
		a[i] += a[i - 1];
	cout<<"Yes"<<endl;
	for(int i = 2; i < maxn; i++)
	{
		int pl = a[i - 1], ss = 0;
		for(int j = a[i - 1] + 1; j <= a[i]; j++)
		{
			printf("%d ", pl), ss++;
			if(ss >= l) pl--, ss = 0;
		}
	}
	return 0;
}