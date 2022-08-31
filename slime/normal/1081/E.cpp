#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
using namespace std;
int n;
ll x[maxn];
ll s[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i += 2)
		scanf("%lld", &x[i]);
	for(int i = n; i >= 2; i -= 2)
	{
		ll lb = 1000000;
		if(i != n) lb = s[i + 1];
		s[i] = s[i - 1] = 0;
		for(int j = 1; j * j <= x[i]; j++)
		{
			if(x[i] % j) continue;
			ll x1 = (j + x[i] / j) / 2, x2 = (x[i] / j - j) / 2;
		
			if((x[i] / j + j) & 1) continue;	
		//	cout<<j<<" "<<x1<<" "<<x2<<endl;
			if(x1 >= lb) continue;
			if(x2 < s[i - 1]) continue;
		//	cout<<x1<<" "<<x2<<endl;
			s[i - 1] = x2, s[i] = x1; 
		}
	
		if(s[i - 1] == 0)
		{	
		//	cout<<"!!!"<<i<<endl;
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for(int i = 1; i <= n; i++)
		printf("%lld ", s[i] * s[i] - s[i - 1] * s[i - 1]);
	return 0;
}