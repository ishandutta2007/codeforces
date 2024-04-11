#include <bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int n, p, k;
ll a[maxn]; 
int main()
{
	cin>>n>>p>>k;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		ll ns = 1;
		for(int j = 0; j < 4; j++)
			ns = ns * a[i] % p;
		ns = ns - a[i] * k;
		ns %= p;
		if(ns < 0) ns += p;
		a[i] = ns; 
	} 
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; )
	{
		int j = i;
		while(a[j] == a[i] && j <= n) j++;
		int u = (j - i);
		ans += u * (u - 1) / 2;
		i = j;
	}
	cout<<ans<<endl;
	return 0;
}