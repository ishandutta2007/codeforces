#include <bits/stdc++.h> 
using namespace std;
int T , n , tot , ans , f[25][25];
string a , b;
struct item
{
	int a , b;
	bool operator < ( const item &x ) const
	{
		if(a == x.a) return b < x.b;
		return a < x.a;
	}
} node[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		memset(f , 0 , sizeof(f));
		for(int i = 0 ; i < 20 ; i++ ) f[i][i] = 1;
		tot = ans = 0;
		scanf("%d" , &n);
		cin >> a >> b;
		for(int i = 0 ; i < n ; i++ )
		{
			int aa = a[i] - 'a' , bb = b[i] - 'a';
			if(aa > bb)
			{
				ans = -1;
				break;
			}
			if(f[aa][bb]) continue;
			ans++; f[aa][bb] = f[bb][aa] = 1;
			for(int j = 0 ; j < 20 ; j++ )
			{
				for(int k = 0 ; k < 20 ; k++ )
				{
					if(f[j][aa] && f[bb][k]) f[j][k] = f[k][j] = 1;
				}
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}