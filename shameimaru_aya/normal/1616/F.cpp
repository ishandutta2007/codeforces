#include <bits/stdc++.h> 
using namespace std;
int T , n , m , mp[70][70] , x , y , z , a[3300] , tot , gg;
const int mod = 3;
bitset< 330 > f[3300] , r[3300] , qwq , p , mm , sf , sr;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); gg = tot = 0;
		memset(a , 0 , sizeof(a)); memset(mp , 0 , sizeof(mp)); 
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d%d" , &x , &y , &z);
			mp[x][y] = mp[y][x] = i;
			if(z > 0) 
			{
				tot++; f[tot] = 0; r[tot] = 0; 
				f[tot][i] = 1; a[tot] = z % mod;
			}
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = i + 1 ; j <= n ; j++ )
			{
				for(int k = j + 1 ; k <= n ; k++ )
				{
					if(mp[i][j] && mp[j][k] && mp[i][k]) 
					{
						tot++; f[tot] = 0; r[tot] = 0; 
						f[tot][mp[i][j]] = f[tot][mp[j][k]] = f[tot][mp[i][k]] = 1; 
					}
				}
			}
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			int id = 0;
			for(int j = i ; j <= tot ; j++ )
				if(f[j][i] || r[j][i]) id = j;
			if(!id) 
			{
				tot++; f[tot] = 0; r[tot] = 0; f[tot][i] = 1; id = tot;
			}
			swap(f[id] , f[i]); swap(r[id] , r[i]); swap(a[id] , a[i]);
			if(r[i][i]) swap(f[i] , r[i]) , a[i] = (mod - a[i]) % mod;
			for(int j = 1 ; j <= tot ; j++ )
			{
				if(i == j) continue;
				if(f[j][i]) 
				{
					mm = f[i]; p = r[i];
					
					sf = f[j] & p; sr = r[j] & p;
					qwq = sr; sr |= sf; sr = p ^ sr; sf = qwq;
					f[j] ^= sf ^ p; r[j] ^= sr ^ p;
					
					sf = f[j] & mm; sr = r[j] & mm;
					qwq = sf; sf |= sr; sf = mm ^ sf; sr = qwq;
					f[j] ^= sf ^ mm; r[j] ^= sr ^ mm;
					(a[j] += mod - a[i]) %= mod;
				}
				else if(r[j][i])
				{
					p = f[i]; mm = r[i];
					
					sf = f[j] & p; sr = r[j] & p;
					qwq = sr; sr |= sf; sr = p ^ sr; sf = qwq;
					f[j] ^= sf ^ p; r[j] ^= sr ^ p;
					
					sf = f[j] & mm; sr = r[j] & mm;
					qwq = sf; sf |= sr; sf = mm ^ sf; sr = qwq;
					f[j] ^= sf ^ mm; r[j] ^= sr ^ mm;
					(a[j] += a[i]) %= mod;
				}
			}
		}
		for(int i = m + 1 ; i <= tot ; i++ )
		{
			if(a[i])
			{
				printf("-1\n"); gg = 1; break;
			}
		}
		if(gg) continue;
		for(int i = 1 ; i <= m ; i++ ) printf("%d " , (a[i] + 2) % mod + 1);
		printf("\n");
	}
	
	
    return 0;
} 
/*
*/