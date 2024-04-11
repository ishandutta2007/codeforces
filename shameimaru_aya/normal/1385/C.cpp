#include<bits/stdc++.h>
using namespace std;
int T , n , l , r , ans , num[210000];
struct item
{
	int id , num;
	bool operator < ( const item &x ) const
	{
		if(x.num == num) return id < x.id;
		return num < x.num;
	}
} node[210000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		l = 1 , r = n , ans = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &node[i].num);
			num[node[i].num]++;
			node[i].id = i;
		}
		sort(node + 1 , node + n + 1);
		for(int i = 1 ; i <= n ; i++ )
		{
			if(node[i].num == node[i - 1].num) continue;
			int L = i , R = i + num[node[i].num] - 1;
			while(L <= R)
			{
//				cerr << L << ' ' << R << endl;
				if(node[L].id == l)
				{
					l++; L++;
					continue;
				}
				if(node[R].id == r)
				{
					r--; R--;
					continue;
				}
				ans = max(ans , node[L].id - 1);
				l = max(l , ans + 2); L++;
			}
		}
		for(int i = 1 ; i <= n ; i++ )
			num[node[i].num] = 0;
		printf("%d\n" , ans);
	}
    return 0;
}