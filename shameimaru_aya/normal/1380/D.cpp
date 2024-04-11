#include<bits/stdc++.h>
using namespace std;
int n , m , a[210000] , b[210000] , usebsk;
long long ans , x , y , k;
map< int , int > mp;
int main()
{
	scanf("%d%d%d%d%d" , &n , &m , &x , &k , &y);
	if(k * y < x) usebsk = 1;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , mp[a[i]] = i;
	for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &b[i]) , b[i] = mp[b[i]];
	b[0] = 0 , b[m + 1] = n + 1;
	for(int i = 0 ; i <= m ; i++ )
	{
		if(b[i] > b[i + 1]) usebsk = -1;
	}
	if(usebsk == -1)
	{
		printf("-1");
		return 0;
	}
	for(int i = 0 ; i <= m ; i++ )
	{
		int qwq = b[i + 1] - b[i] - 1 , maxx = 0;
		for(int j = b[i] + 1 ; j < b[i + 1] ; j++ ) maxx = max(a[j] , maxx);
		if(usebsk)
		{
			if(maxx < max(a[b[i + 1]] , a[b[i]])) ans += qwq * y;
			else
			{
				if(qwq >= k) ans += (qwq - k) * y + x;
				else
				{
					ans = -1;
					break;
				}
			}
		}
		else
		{
			int qaq = qwq / k;
			if(qaq == 0)
			{
				if(maxx > max(a[b[i + 1]] , a[b[i]]))
				{
					ans = -1;
					break;
				}
				else ans += qwq * y;
			}
			else ans += qaq * x + qwq % k * y;
		}
	}
	printf("%lld" , ans);
    return 0;
}
/*
*/