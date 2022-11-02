#include<bits/stdc++.h>
using namespace std;
int n , m , l[330000] , r[330000] , a[30] , b[30];
int f[330000] , num[330000] , sum[50][330000] , L , R;
long long jc[330000] , inv[330000] , cnt , qwq , ans;
const int mod = 998244353;
inline void init()
{
	jc[0] = inv[0] = inv[1] = 1;
	for(int i = 1 ; i <= 300000 ; i++ ) jc[i] = jc[i - 1] * i % mod;
	for(int i = 2 ; i <= 300000 ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2 ; i <= 300000 ; i++ ) inv[i] = inv[i - 1] * inv[i] % mod;
}
inline long long C( int a , int b )
{
	if(a < 0 || b < 0 || a < b) return 0;
	return jc[a] * inv[b] % mod * inv[a - b] % mod;
}
int main()
{
	init();
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d" , &l[i] , &r[i]);
		num[l[i]]++; num[r[i] + 1]--;
	}
	for(int i = 1 ; i <= m ; i++ ) scanf("%d%d" , &a[i] , &b[i]);
	for(int i = 1 ; i <= n ; i++ ) num[i] += num[i - 1];
	for(int k = 0 ; k <= 40 ; k++ )
		for(int i = 1 ; i <= n ; i++ )
			sum[k][i] = (sum[k][i - 1] + C(num[i] - k , i - k)) % mod;
	/*
	for(int k = 0 ; k <= 40 ; k++ )
	{
		for(int i = 1 ; i <= n ; i++ ) cerr << C(num[i] - k , i - k) << ' ';
		cerr << endl;
	}
	*/
	for(int i = 0 ; i < (1 << m) ; i++ )
	{
		L = 1 , R = n , cnt = 0 , qwq = 1;
		for(int j = 1 ; j <= m ; j++ )
		{
			if(!(i & (1 << j - 1))) continue;
			L = max(L , l[a[j]]); R = min(R , r[a[j]]);
			L = max(L , l[b[j]]); R = min(R , r[b[j]]);
			f[a[j]]++; f[b[j]]++;
			if(f[a[j]] == 1) cnt++;
			if(f[b[j]] == 1) cnt++;
			qwq *= -1; 
		}
		if(L <= R)
		ans = (ans + (qwq * (sum[cnt][R] - sum[cnt][L - 1]) % mod + mod)) % mod;
		for(int j = 1 ; j <= m ; j++ )
		{
			if(!(i & (1 << j - 1))) continue;
			f[a[j]]--; f[b[j]]--;
		}
	}
	printf("%d" , ans);
    return 0;
}
/*
10 10
6 9
6 7
1 6
10 10
5 9
3 9
2 10
5 7
9 10
5 10
9 10
2 6
1 7
3 8
6 10
5 9
1 5
1 4
5 6
7 8
*/