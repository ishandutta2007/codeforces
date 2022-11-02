#include <bits/stdc++.h> 
using namespace std;
struct item
{
	long long a , b;
	bool operator < ( const item &x )
	{
		return a > x.a;
	}
} node[110000];
int T , n , m , a;
long long ans , s[110000];
int binary( int l , int r , int k )
{
	if(l > r) return a;
	int mid = l + r >> 1;
	if(node[mid].a > k) return a = mid , binary(mid + 1 , r , k);
	return binary(l , mid - 1 , k);
}
int main()
{
	scanf("%d" , &T); node[0].a = 2e9;
	while(T--)
	{
		ans = 0;
		scanf("%d%d" , &n , &m);
		for(int i = 1; i <= m; i++ ) scanf("%lld%lld" , &node[i].a , &node[i].b);
		sort(node + 1 , node + m + 1);
		for(int i = 1; i <= m; i++ ) s[i] = s[i - 1] + node[i].a;
		for(int i = 1; i <= m; i++ )
		{
			int k = binary(0 , m , node[i].b);
			if(k >= n) k = n - 1;
			if(i > k)
			ans = max(ans , s[k] + node[i].a + node[i].b * (n - k - 1));
			else ans = max(ans , s[k] + node[i].b * (n - k));
		}
		if(n <= m) ans = max(ans , s[n]);
		printf("%lld\n" , ans);
	}
	return 0;
}