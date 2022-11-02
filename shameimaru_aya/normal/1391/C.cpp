#include<bits/stdc++.h>
using namespace std;
int n;
long long ans , s;
const int mod = 1e9 + 7;
int main()
{
	scanf("%d" , &n);
	ans = s = 1;
	for(int i = 2 ; i <= n ; i++ ) ans = ans * i % mod , s = s * 2 % mod;
	printf("%d" , ((ans - s) % mod + mod) % mod);
	return 0;
}