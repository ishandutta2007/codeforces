#include <bits/stdc++.h>
#define F first
#define S second
#define pr pair< int , int >
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n , f , b , tot , t , ans[1100000];
int pri[1100000] , ispri[1100000] , cnt , minn[1100000] , num[1100000] , minpri[1100000];
unsigned long long w[1100000] , p;
map< unsigned long long , int > mp;
void init( int x = 0 , int y = 0 , int z = 0 )
{
	p = 0;
	for(int i = 1 ; i <= x ; i++ ) p ^= w[i];
	for(int i = 1 ; i <= y ; i++ ) p ^= w[i];
	for(int i = 1 ; i <= z ; i++ ) p ^= w[i];
}
int find()
{
	long long qwq = 0;
	for(int i = 1 ; i <= n ; i++ )
	{
		qwq ^= w[i];
		if(qwq == p) return i;
	}
	return 0;
}
pr find2()
{
	long long qwq = 0; mp.clear();
	for(int i = 1 ; i <= n ; i++ )
	{
		qwq ^= w[i]; 
		if(mp[qwq ^ p]) return make_pair(mp[qwq ^ p] , i);
		mp[qwq] = i;
	}
	return make_pair(0 , 0);
}
int main()
{
	scanf("%d" , &n);
	if(n == 1)
	{
		printf("1\n1");
		return 0;
	}
	for(int i = 2 ; i <= 1000000 ; i++ )
	{
		if(!ispri[i]) pri[++cnt] = i , minn[i] = i , num[i] = 1 , w[i] = 1ull * rng() * rng();
		for(int j = 1 ; j <= cnt && i * pri[j] <= 1000000 ; j++ )
		{
			ispri[i * pri[j]] = 1; minn[i * pri[j]] = pri[j]; num[i * pri[j]] = 1;
			w[i * pri[j]] = w[i] ^ w[pri[j]];
			if(i % pri[j] == 0)
			{
				num[i * pri[j]] = num[i] + 1;
				break;
			}
		}
	}
	if(n % 2 == 0)
	{
		if(n % 4 == 0)
		{
			printf("%d\n" , n - 1);
			for(int i = 1 ; i <= n ; i++ )
			{
				if(i == n / 2) continue;
				printf("%d " , i);
			}
		}
		else
		{
			init(n / 2 , 2);
			int qwq = find();
			if(qwq)
			{
				printf("%d\n" , n - 1);
				for(int i = 1 ; i <= n ; i++ )
				{
					if(i == qwq) continue;
					printf("%d " , i);
				}
			}
			else
			{
				printf("%d\n" , n - 2);
				for(int i = 1 ; i <= n ; i++ )
				{
					if(i == n / 2 || i == 2) continue;
					printf("%d " , i);
				}	
			}
		}
	}
	else 
	{
		if((n - 1) % 4 == 0)
		{
			init(n / 2 , n);
			int qwq = find();
			if(qwq)
			{
				printf("%d\n" , n - 1);
				for(int i = 1 ; i <= n ; i++ )
				{
					if(i == qwq) continue;
					printf("%d " , i);
				}
			}
			else
			{
				printf("%d\n" , n - 2);
				for(int i = 1 ; i <= n ; i++ )
				{
					if(i == n / 2 || i == n) continue;
					printf("%d " , i);
				}
			}
		}
		else
		{
			init(n / 2 , 2 , n);
			int qwq = find();
			if(qwq)
			{
				printf("%d\n" , n - 1);
				for(int i = 1 ; i <= n ; i++ )
				{
					if(i == qwq) continue;
					printf("%d " , i);
				}
			}
			else
			{
				pr qwq = find2();
				if(qwq.F)
				{
					printf("%d\n" , n - 2);
					for(int i = 1 ; i <= n ; i++ )
					{
						if(i == qwq.F || i == qwq.S) continue;
						printf("%d " , i);
					}
					return 0;
				}
				printf("%d\n" , n - 3);
				for(int i = 1 ; i <= n ; i++ )
				{
					if(i == n / 2 || i == 2 || i == n) continue;
					printf("%d " , i);
				}	
			}
		}
	}
	return 0;
}